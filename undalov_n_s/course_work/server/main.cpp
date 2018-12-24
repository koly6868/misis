#include <QCoreApplication>
#include "server.h"
#include <QTcpSocket>
#include <iostream>
#include "configuration_manager.h"
#include "console.h"

FileTcpServer* Configure(QObject* parent, const ConfigurationManager& configManag, char tun);

int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  ConfigurationManager configManag;
  char tun;
  cout << "use default settings? yes - y, no - n" << endl;
  cin >> tun;

  FileTcpServer* serv = Configure(&a, configManag, tun);

  return a.exec();
}

FileTcpServer* Configure(QObject* parent, const ConfigurationManager& configManag, char tun)
{
  using namespace std;
  QString adr;
  quint16 port;
  switch (tun)
  {
  case 'y':
    port = configManag.GetValue("port").toInt();
    adr = configManag.GetValue("ip");
    break;
  case 'n':
    cout << "enter your adress" << endl;
    cin >> adr;
    cout << "enter port" << endl;
    cin >> port;
    break;
  default:
    cout << "something went wrong" << endl;
    break;
  }
  qDebug() << configManag.GetValue("storagePath");
  qDebug() << QHostAddress(adr) << endl;
  return new FileTcpServer(parent, port, QHostAddress(adr), configManag.GetValue("storagePath"));
}

