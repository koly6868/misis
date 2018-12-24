#ifndef SERVER_2018
#define SERVER_2018

#include "file_systeam.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "file_systeam.h"
#include <QDebug>
#include <QCoreApplication>
#include "client.h"
#include "enums.h"

class FileTcpServer : public QObject
{
  Q_OBJECT
public:
  explicit FileTcpServer(QObject *parent = nullptr, quint16 port = 6000, QString storagePath = ".\\");
  FileTcpServer(QObject *parent, quint16 port, QHostAddress adr, QString storagePath);
  ~FileTcpServer();
  public slots:
  void slotNewConnection();
  void slotServerRead(QByteArray str);
  void slotClientDisconnected();

private:
  QTcpServer * mTcpServer;
  Client * client;
  FileSysteam* fs_{};
};

#endif // !SERVER_2018

