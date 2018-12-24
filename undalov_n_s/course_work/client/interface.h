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

  void GetListOfFilesReq();
  void UploadFileReq(QString fileName);
  void DownloadFileReq(QString fileName);
public slots:

signals:
  void GetListOfFilesReqSignal();
  void UploadFileReqSignal(QString);
  void DownloadFileReqSignal(QString);
private:

};

#endif // !INTERFACE_H
