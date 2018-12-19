#include "file_systeam.h"

FileSysteam::FileSysteam(const QString& path)
  : dir_(path)
{
}

QStringList FileSysteam::ShowFiles() const
{
  return dir_.entryList();
}
