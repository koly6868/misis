#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtCore>
#include "client_controller.h"

class Interface : public QObject
{
Q_OBJECT

public:
  Interface(ClientController* cont);
  ~Interface();
//запрос на список файла на сервере
  void GetListOfFilesReq();
//запрос на загрузку файла на сервер
  void UploadFileReq(QString fileName);
//запрос на скачивание файла с сервера
  void DownloadFileReq(QString fileName);
public slots:

signals:
  void GetListOfFilesReqSignal();
  void UploadFileReqSignal(QString);
  void DownloadFileReqSignal(QString);
private:

};

#endif // !INTERFACE_H
