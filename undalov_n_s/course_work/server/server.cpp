#include "server.h"

FileTcpServer::FileTcpServer(QObject *parent, quint16 port, QString storagePath) : QObject(parent)
{
  mTcpServer = new QTcpServer(this);
  fs_ = new FileSysteam(storagePath);
  connect(mTcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

  if (!mTcpServer->listen(QHostAddress::LocalHost, port))
  {
    qDebug() << "server is not started";
  }
  else
  {
    qDebug() << "server is started on port " << port;
  }
}



FileTcpServer::FileTcpServer(QObject *parent, quint16 port, QHostAddress adr, QString storagePath)
{
  mTcpServer = new QTcpServer(this);
  fs_ = new FileSysteam(storagePath);
  connect(mTcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

  if (!mTcpServer->listen(adr, port))
  {
    qDebug() << "server is not started";
  }
  else
  {
    qDebug() << "server is started on port " << port;
  }
}

void FileTcpServer::slotNewConnection()
{
  QTcpSocket* sock = mTcpServer->nextPendingConnection();
  qDebug() << sock->state() << endl;

  client = new Client(this, sock);
  qDebug() << "conected" << endl;
  QJsonObject o;
  o.insert("command", INFO);
  client->sendMessage(QJsonDocument(o).toBinaryData());
  client->sendMessage("conected");

  connect(client, SIGNAL(whenRecivedBytes(QByteArray)), this, SLOT(slotServerRead(QByteArray)));
  //connect(mTcpSocket, &QTcpSocket::disconnected, this, &FileTcpServer::slotClientDisconnected);
}



void FileTcpServer::slotServerRead(QByteArray str)
{
  QJsonObject settings;
  if (client->message_part == 0)
  {
    settings = QJsonDocument::fromBinaryData(str).object();
    client->comadnd_ = static_cast<command>(settings["command"].toInt());
  }
  qDebug() << QJsonDocument(settings)<<endl;


  switch (client->comadnd_)
  {
  case GET_LIST_OF_FILES:
    client->sendMessage(QJsonDocument(settings).toBinaryData());
    client->sendMessage(fs_->ShowFiles().join(',').toUtf8());
    client->message_part = 0;
    break;
  case UPLOAD_FILE:
    if (client->message_part == 0)
    { 
      QString name = settings["name"].toString();
      QString newName = name;
      int number = 0;
      while (fs_->ShowFiles().contains(newName))
      {
        number++;
        newName = name;
        newName.replace(QRegExp("\\."), '(' + QString().setNum(number) + ").");
      } 
      fs_->OpenFile(newName, QIODevice::WriteOnly);
      client->cont_blocks = settings["countBlocks"].toInt();
      client->message_part++;
    }
    else
    {
      fs_->WriteAllToFile(str);
      client->message_part++;
      if (client->message_part == client->cont_blocks)
      {
        fs_->Close();
        client->message_part = 0;
        client->cont_blocks = 0;
      }
    }
    break;
  case DOWNLOAD_FILE:
    if (!fs_->OpenFile(settings["name"].toString()))
    {
       settings.insert("status","error");
       client->sendMessage(QJsonDocument(settings).toBinaryData());
    }
    else
    {
      qint64 countBlocks = (fs_->FileSize() % client->part_file_size) == 0 ? fs_->FileSize() / client->part_file_size : fs_->FileSize() / client->part_file_size + 1;
      settings.insert("status","ok");
      settings.insert("countBlocks", countBlocks);
      client->sendMessage(QJsonDocument(settings).toBinaryData());
      for (int i = 0; i < countBlocks; i++)
      {
        client->sendMessage(fs_->ReadPartOfFile(client->part_file_size));
      }
      client->message_part = 0;
    }
    break;
  default:
    break;
  }

}



void FileTcpServer::slotClientDisconnected()
{
  qDebug() << "disconected" << endl;
  //mTcpSocket->close();
}


FileTcpServer::~FileTcpServer()
{
  qDebug() << "serever deleted" << endl;
}

