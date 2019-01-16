#include "client.h"




Client::Client(QObject* parent, QTcpSocket* socket)
  : QObject(parent)
  , block_size_(0)
{
  socket_ = socket;
  qDebug() << socket_->state();
  connect(socket_, SIGNAL(readyRead()), this, SLOT(onReciveBytes()));
  connect(socket_, &QTcpSocket::disconnected, this, &Client::onDisonected);
}



Client::~Client()
{
};



void Client::SendMessage(QByteArray message)
{
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out << static_cast<quint32>(0);
  out << message;
  out.device()->seek(0);
  out << static_cast<quint32>(block.size() - sizeof(quint32));

  socket_->write(block);
};



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
  if (socket_->bytesAvailable() > 0) onReciveBytes();
}



void Client::onDisonected()
{
  emit disconnected();
}



