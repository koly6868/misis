#include "client.h"



Client::Client(QObject *parent, quint16 port)
  : QObject(parent)
  , block_size_(0)
{
  socket_ = new QTcpSocket(this);
  socket_->bind(QHostAddress::LocalHost, port);
  connect(socket_, SIGNAL(readyRead()), this, SLOT(onReciveBytes()));
};



Client::Client(QObject* parent, QTcpSocket* socket)
  : QObject(parent)
  , block_size_(0)
{
  socket_ = socket;
}



Client::Client(QObject* parent, quint16 port, QHostAddress adr)
  : QObject(parent)
  , block_size_(0)
{
  socket_ = new QTcpSocket(this);
  socket_->bind(adr, port);
  connect(socket_, SIGNAL(readyRead()), this, SLOT(onReciveBytes()));
}


Client::~Client()
{
  socket_->close();
};



void Client::SendMessage(QByteArray message)
{
  //создание блока
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  //резерв на размер блока
  out << static_cast<quint32>(0);
  //запись сообщения
  out << message;
  // возврат в начало
  out.device()->seek(0);
  //запись размера сообщения
  out << static_cast<quint32>(block.size() - sizeof(quint32));
  //запись в сокет
  socket_->write(block);
}



bool Client::ConnectToHost(QHostAddress adr, quint16 port)
{
  //открыть текущий сокет
  socket_->open(QIODevice::ReadWrite);
  //присоединение к серверу
  socket_->connectToHost(adr, port);
  if (socket_->waitForConnected(3000))
  {
    qDebug() << "Ready to work";
  }
  else
  {
    qDebug() << "Not open";
  }
  return true;
};



void Client::onConnectionError()
{
  qDebug() << "not conected" << endl;
}



void Client::onReciveBytes()
{
  QDataStream in(socket_);
  if (block_size_ == 0)
  {
    if (socket_->bytesAvailable() < sizeof(quint32))
    {
      return;
    }
    in >> block_size_;
  }
  if (socket_->bytesAvailable() >= block_size_)
  {
    char* mes = new char[block_size_];
    in.readBytes(mes, block_size_);
    emit whenRecivedBytes(QByteArray(mes, block_size_));
    block_size_ = 0;
  }
  //если в сокете еще одно сообщение, сразу вызываем этот же метод
  if (socket_->bytesAvailable() > 0) onReciveBytes();
}

bool Client::IsConected()
{
  return socket_->state() == QTcpSocket::ConnectedState;
}

void Client::onDisonected()
{
  emit disconnected();
}




