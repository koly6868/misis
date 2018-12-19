#ifndef SERVER_2018
#define SERVER_2018

#include "file_systeam.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "client.h"

class FileTcpServer : public QObject
{
  Q_OBJECT
public:
  explicit FileTcpServer(QObject *parent = nullptr, quint16 port = 6000);
  FileTcpServer(QObject *parent, quint16 port, QHostAddress adr);
  ~FileTcpServer();
  public slots:
  void slotNewConnection();
  void slotServerRead(QByteArray str);
  void slotClientDisconnected();

private:
  QFile* currentFile{nullptr};
  QTcpServer * mTcpServer;
  Client * client;
};

#endif // !SERVER_2018

