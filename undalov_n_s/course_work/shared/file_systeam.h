#ifndef FILE_SYSTEAM_H
#define FILE_SYSTEAM_H
#include <QtCore>

class FileSysteam
{
public:
  FileSysteam(const QString& path = ".\\");
  ~FileSysteam();
//список файлов
  QStringList ShowFiles() const;
//открыть файл
  bool OpenFile(QString fileName, QFlags<QIODevice::OpenModeFlag> flags = QIODevice::ReadWrite);
//считать все данные файлы
  QByteArray ReadAllFromFile();
//считать часть файла
  QByteArray ReadPartOfFile(qint64 size);
//размер файла
  qint64 FileSize();
//записать все в файл
  void WriteAllToFile(QByteArray data);
//закрыть файл
  void Close();

private:
  QString path_{".\\"};
  QFile* file{ nullptr };
};

#endif // !FILE_SYSTEAM_H
