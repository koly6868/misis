#ifndef FILE_SYSTEAM_H
#define FILE_SYSTEAM_H
#include <QtCore>

class FileSysteam
{
public:
  FileSysteam(const QString& path = ".\\");
  ~FileSysteam() = default;
  QStringList ShowFiles() const;
private:
  QDir dir_{".\\"};
};

#endif // !FILE_SYSTEAM_H
