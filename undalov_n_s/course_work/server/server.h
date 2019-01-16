#ifndef SERVER_2018
#define SERVER_2018

#include <QDebug>
#include <QCoreApplication>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "../shared/file_systeam.h"
#include "client.h"
#include "../shared/enums.h"



class FileTcpServer : public QObject
{
  Q_OBJECT
public:
  explicit FileTcpServer(QObject *parent = nullptr, quint16 port = 6000, QString storagePath = ".\\");
  FileTcpServer(QObject *parent, quint16 port, QHostAddress adr, QString storagePath);
  ~FileTcpServer();

  public slots:
//подключение нового клиента
  void slotNewConnection();
//чтение запросов от клиентов
  void slotServerRead(QByteArray str);
//при отключении клиента
  void onClientDisconected();

private:
  QTcpServer * mTcpServer;
  FileSysteam* fs_{};
};

#endif // !SERVER_2018

