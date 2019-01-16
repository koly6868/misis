#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H


#include <QtCore>
#include "../shared/enums.h"
#include "client.h"
#include "../shared/console.h"

class ClientController : public QObject
{
Q_OBJECT

public:
  ClientController(QCoreApplication* parent, Client* cl, QString filesPath = ".\\files", uint block_size = 4096);
  ~ClientController();
//список файлов на текущей машине
  QString GetListOfFiles();

public slots:
//отправка данных
  void SendMessage(QByteArray message);
//обработка полученных данных
  void onResvieMessage(QByteArray data);
//запрос на список файлов сервера  
  void GetListOfFilesReq();
//запрос на загрузку файла на сервер
  void UploadFileReq(QString fileName);
//запрос на скачивание файла с сервера
  void DownloadFileReq(QString fileName);
//состояние подключения
  bool IsConected();

signals:
//при считывании данных
  void Reading();
private:
//обработка запроса на скачивание файла
  void onDownloadFile(QJsonObject info, QByteArray data);
//обработка запроса на получение списка файлов на сервере
  void onGetListOfFiles(QString list);
//обработка запроса на загрузку файла на сервер
  void onUploadFile(QJsonObject info);

  Client* client{nullptr};
  FileSysteam* fs_{nullptr};
  command command_;
  int message_part_{0};
  int block_size_{4096};
};

#endif // CLIENT_CONTROLLER_H
