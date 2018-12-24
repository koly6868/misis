#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QtCore>
#include <QHostAddress>
#include "enums.h"

class Client : public QObject
{
  Q_OBJECT
public:
  Client(QObject *parent = nullptr, quint16 port = 6001);
  Client(QObject *parent, QTcpSocket* socket);
  ~Client();
  bool ConnectToHost(QHostAddress adr, quint16 port);
  void sendMessage(QByteArray str);

  public slots:
  void onConnectionError();
  void onReciveBytes();

signals:
  void whenRecivedBytes(QByteArray str);
public:
  int cont_blocks{1};
  int message_part{0};
  command comadnd_;
  uint part_file_size{ 4096 };

private:
  quint32 block_size_{ 0 };
  QTcpSocket * socket_{ nullptr };
};


#endif // CLIENT_H
