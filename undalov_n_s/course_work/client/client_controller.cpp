#include "client_controller.h"

ClientController::ClientController(Client* cl, QString filesPaht, uint block_size)
{
  if (block_size == 0)
  {
    throw exception("uncorrect block size");
  }
  client = cl;
  block_size_ = block_size;
  fs_ = new FileSysteam(filesPaht);
  connect(client, SIGNAL(whenRecivedBytes(QByteArray)), this, SLOT(onResvieMessage(QByteArray)));
}



void ClientController::SendMessage(QByteArray message)
{
  client->SendMessage(message);
}



ClientController::~ClientController()
{
  delete client;
}



QString ClientController::GetListOfFiles()
{
  return fs_->ShowFiles().join('\n');
}



void ClientController::onResvieMessage(QByteArray data)
{
  emit Reading();
  QJsonObject settings;

  if (message_part_ == 0)
  {
    settings = QJsonDocument::fromBinaryData(data).object();
    command_ = static_cast<command>(settings["command"].toInt());
  }

  switch (command_)
  {
  case GET_LIST_OF_FILES:
    if (message_part_ == 0)
    {
      message_part_++;
    }
    else
    {
      onGetListOfFiles(QString(data));
      message_part_ = 0;
    }
    break;
  case INFO:
    if (message_part_ == 0)
    {
      message_part_++;
    }
    else
    {
      cout << QString(data) << endl;
      message_part_ = 0;
    }
    break;
  case DOWNLOAD_FILE:
    onDownloadFile(settings,data);
    break;
  default:
    break;
  }

}



void ClientController::GetListOfFilesReq()
{
  QJsonDocument doc;
  QJsonObject settings = doc.object();
  settings.insert("command", GET_LIST_OF_FILES);
  SendMessage(QJsonDocument(settings).toBinaryData());
}



void ClientController::UploadFileReq(QString fileName)
{
  if (!fs_->OpenFile(fileName)) qDebug() << "file not open" << endl;

  qint64 countBlocks = (fs_->FileSize() % block_size_) == 0 ? fs_->FileSize() / block_size_ : fs_->FileSize() / block_size_ + 1;
  QJsonDocument doc;
  QJsonObject settings = doc.object();
  settings.insert("name", fileName);
  settings.insert("command", UPLOAD_FILE);
  settings.insert("countBlocks", countBlocks + 1);

  client->SendMessage(QJsonDocument(settings).toBinaryData());
  for (int i = 0; i < countBlocks; i++)
  {
    client->SendMessage(fs_->ReadPartOfFile(block_size_));
  }
  fs_->Close();
}



void ClientController::DownloadFileReq(QString fileName)
{
  QJsonDocument doc;
  QJsonObject settings = doc.object();
  settings.insert("name", fileName);
  settings.insert("command", DOWNLOAD_FILE);

  client->SendMessage(QJsonDocument(settings).toBinaryData());
}

bool ClientController::IsConected()
{
  return client->IsConected();
}



void ClientController::onGetListOfFiles(QString list)
{
  cout << list << endl;
}

void ClientController::onDownloadFile(QJsonObject info, QByteArray data)
{
  if (message_part_ == 0)
  {
    client->part_file_size = info["countBlocks"].toInt();
    message_part_++;

    QString name = info["name"].toString();
    QString newName = name;
    int number = 0;
    while (fs_->ShowFiles().contains(newName))
    {
      number++;
      newName = name;
      newName.replace(QRegExp("\\."), '(' + QString().setNum(number) + ").");
    }
    fs_->OpenFile(newName, QIODevice::WriteOnly);
  }
  else
  {
    fs_->WriteAllToFile(data);
    if (message_part_ == client->part_file_size)
    {
      fs_->Close();
      message_part_ = 0;
    }
  }
}
