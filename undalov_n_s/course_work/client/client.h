#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QtCore>
#include <QHostAddress>
#include "file_systeam.h"

class Client : public QObject
{
  Q_OBJECT
public:
  Client(QObject *parent = nullptr, quint16 port = 6001);
  Client(QObject *parent, QTcpSocket* socket);
  Client(QObject *parent, quint16 port, QHostAddress adr);
  ~Client();

  public slots:
  bool ConnectToHost(QHostAddress adr, quint16 port);
  void SendMessage(QByteArray str);
  void onConnectionError();
  void onReciveBytes();
  bool IsConected();

signals:
  void whenRecivedBytes(QByteArray str);
  void disconnected();
public:
  int message_part{ 0 };
  uint part_file_size{ 4096 };
  FileSysteam* fs_{nullptr};
 
 private:
  void onDisonected();

private:
  quint32 block_size_{ 0 };
  QTcpSocket* socket_{ nullptr };
};
#endif // CLIENT_H
