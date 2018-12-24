#include "file_systeam.h"

FileSysteam::FileSysteam(const QString& path)
  : dir_(path)
{
  path_ = path;
}



QStringList FileSysteam::ShowFiles() const
{
  return dir_.entryList();
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