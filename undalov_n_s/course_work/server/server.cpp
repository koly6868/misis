#include "server.h"
#include <QDebug>
#include <QCoreApplication>

FileTcpServer::FileTcpServer(QObject *parent, quint16 port) : QObject(parent)
{
  mTcpServer = new QTcpServer(this);

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



FileTcpServer::FileTcpServer(QObject *parent, quint16 port, QHostAddress adr)
{
  mTcpServer = new QTcpServer(this);

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
  client->sendMessage("conected");
  
  connect(client, SIGNAL(whenRecivedBytes(QByteArray)), this, SLOT(slotServerRead(QByteArray)));
  //connect(mTcpSocket, &QTcpSocket::disconnected, this, &FileTcpServer::slotClientDisconnected);
}

void FileTcpServer::slotServerRead(QByteArray str)
{
  qDebug() << "reading" << endl;
  QJsonObject settings;
  switch (client->message_part)
  {
    case 0:
      settings = QJsonDocument::fromBinaryData(str).object();
      qDebug() << "File Name: " << settings["name"].toString() << endl;
      currentFile = new QFile(settings["name"].toString());
      client->message_part++;
      break;
    case 1:
      qDebug() << "File state: " << currentFile->open(QIODevice::WriteOnly);
      currentFile->write(str);
      client->message_part++;
      currentFile->close();
      break;
  default:
    break;
  }
  //client->sendMessage(str.toUtf8());

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

