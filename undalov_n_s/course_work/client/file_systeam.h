#ifndef FILE_SYSTEAM_H
#define FILE_SYSTEAM_H
#include <QtCore>

class FileSysteam
{
public:
  FileSysteam(const QString& path = ".\\");
  ~FileSysteam();
  QStringList ShowFiles() const;
  bool OpenFile(QString fileName, QFlags<QIODevice::OpenModeFlag> flags = QIODevice::ReadWrite);
  QByteArray ReadAllFromFile();
  QByteArray ReadPartOfFile(qint64 size);
  qint64 FileSize();
  void WriteAllToFile(QByteArray data);
  void Close();

private:
  QString path_{".\\"};
  QFile* file{ nullptr };
};

#endif // !FILE_SYSTEAM_H
