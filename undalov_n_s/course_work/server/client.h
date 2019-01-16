#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QtCore>
#include <QHostAddress>
#include "../shared/enums.h"

class Client : public QObject
{
  Q_OBJECT
public:
  Client(QObject *parent, QTcpSocket* socket);
  ~Client();
//отправить данные
  void SendMessage(QByteArray str);

public slots:
  void onReciveBytes();
  void onDisonected();

signals:
//при получении данных
  void whenRecivedBytes(QByteArray str);
//при отключении
  void disconnected();

public:
  int cont_blocks{ 1 };
  int message_part{ 0 };
  command comadnd_;
  uint part_file_size{ 4096 };

private:
  quint32 block_size_{ 0 };
  QTcpSocket * socket_{ nullptr };
};


#endif // CLIENT_H
