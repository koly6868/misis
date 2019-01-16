#ifndef CLIENT_SERVER_H
#define CLIENT_SERVER_H

#include <QTcpSocket>
#include <QtCore>
#include <QHostAddress>
#include "../shared//file_systeam.h"

class Client : public QObject
{
  Q_OBJECT
public:
  Client(QObject *parent = nullptr, quint16 port = 6001);
  Client(QObject *parent, QTcpSocket* socket);
  Client(QObject *parent, quint16 port, QHostAddress adr);
  ~Client();

  public slots:
  //подключение к серверу
    bool ConnectToHost(QHostAddress adr, quint16 port);
  //отправка данных
    void SendMessage(QByteArray str);
  //при ошибке подключения
    void onConnectionError();
  //обработка полученных данных
    void onReciveBytes();
  //проверка состояния соединения
    bool IsConected();

signals:
//получение данных
  void whenRecivedBytes(QByteArray str);
//отключение от сервера
  void disconnected();
public:
  int message_part{ 0 };
  uint part_file_size{ 4096 };
  FileSysteam* fs_{nullptr};
 
 private:
 //действия при отключении
  void onDisonected();

private:
  quint32 block_size_{ 0 };
  QTcpSocket* socket_{ nullptr };
};
#endif // CLIENT_SERVER_H
