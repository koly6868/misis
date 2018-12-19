#include "client.h"
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "console.h"
#include "configuration_manager.h"

Client* Configure(QObject* parent, const ConfigurationManager& confManag, char tun);
bool ConnectToHost(Client* client, const ConfigurationManager& confManag, char tun);
QJsonDocument SettingsFile(QString name = "test");

int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  ConfigurationManager confManag;
  char tun;
  cout << "use default settings? yes - y, no - n" << endl;
  cin >> tun;
  //Client* client = new Client();
  Client* client = Configure(&a, confManag, tun);

  ConnectToHost(client, confManag, tun);
  client->WaitForAvailableData();
  QString file_name;
  cout << "Enter a file name" << endl;
  cin >> file_name;
  QFile file(file_name);
  if (!file.open(QIODevice::ReadOnly)) qDebug() << "file not open" << endl;
  QByteArray data = file.readAll();
  cout << data;
  //client->ConnectToHost(QHostAddress::LocalHost, 6000);
  client->sendMessage(SettingsFile(file_name).toBinaryData());
  client->sendMessage(data);
  //      std::string inp;
  //      while (inp != "exit")
  //      {
  //      cin >> inp;
  //      cout << inp << " sended" << endl;

  //      client->sendMessage(QString(inp.c_str()).toUtf8());
  //      }
  return a.exec();
}

Client* Configure(QObject* parent, const ConfigurationManager& confManag, char tun)
{
  using namespace std;
  QString adr;
  quint16 port;
  switch (tun)
  {
  case 'y':
    port = confManag.GetValue("port").toInt();
    adr = confManag.GetValue("ip");
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
  qDebug() << QHostAddress(adr) << endl;
  return new Client(parent, port, QHostAddress(adr));
}

QJsonDocument SettingsFile(QString name)
{
  QJsonDocument doc;
  QJsonObject settings = doc.object();
  settings.insert("name", name);
  settings.insert("author", "Shine");
  return QJsonDocument(settings);
}

bool ConnectToHost(Client* client, const ConfigurationManager& confManag, char tun)
{
  QString adr;
  quint16 port;
  switch (tun)
  {
  case 'y':
    port = confManag.GetValue("portServer").toInt();
    adr = confManag.GetValue("ipServer");
    break;
  case 'n':
    cout << "enter host adress" << endl;
    cin >> adr;
    cout << "enter port" << endl;
    cin >> port;
    break;
  default:
    cout << "something went wrong" << endl;
    break;
  }
  return client->ConnectToHost(QHostAddress(adr), port);
}







