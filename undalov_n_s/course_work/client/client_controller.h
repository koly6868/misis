#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H


#include <QtCore>
#include "enums.h"
#include "client.h"
#include "console.h"

class ClientController : public QObject
{
Q_OBJECT

public:
  ClientController(Client* cl, QString filesPath = ".\\files", uint block_size = 4096);
  ~ClientController();
  QString GetListOfFiles();

public slots:
  void SendMessage(QByteArray message);
  void onResvieMessage(QByteArray data);
  void GetListOfFilesReq();
  void UploadFileReq(QString fileName);
  void DownloadFileReq(QString fileName);
  bool IsConected();

signals:
  void Reading();

private:
  void onDownloadFile(QJsonObject info, QByteArray data);
  void onGetListOfFiles(QString list);
  Client* client{nullptr};
  FileSysteam* fs_{nullptr};

  command command_;
  int message_part_{0};
  int block_size_{4096};
};

#endif // CLIENT_CONTROLLER_H
