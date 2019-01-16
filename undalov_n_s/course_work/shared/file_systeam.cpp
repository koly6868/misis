#include "file_systeam.h"

FileSysteam::FileSysteam(const QString& path)
{
  path_ = path;
  QDir dir (path_);
  if (!dir.exists())
  {
    dir.mkdir("files");
  }
}



QStringList FileSysteam::ShowFiles() const
{
  QStringList resp = QDir(path_).entryList();
  resp.removeOne(".");
  resp.removeOne("..");
  return resp;
}



bool FileSysteam::OpenFile(QString fileName, QFlags<QIODevice::OpenModeFlag> flags)
{
  file = new QFile(path_ + "\\" + fileName);
  return file->open(flags);
}



QByteArray FileSysteam::ReadAllFromFile()
{
  if (!file->isOpen()) throw std::exception("file not open");
  return file->readAll();
}



QByteArray FileSysteam::ReadPartOfFile(qint64 size)
{
  return file->read(size);
}

qint64 FileSysteam::FileSize()
{
  return file->size();
}



void FileSysteam::WriteAllToFile(QByteArray data)
{
  if (!file->isOpen()) throw std::exception("file not open");
  file->write(data);
}



void FileSysteam::Close()
{
  file->close();
}



FileSysteam::~FileSysteam()
{
  if (file->isOpen())
  {
    file->close();
  }
}