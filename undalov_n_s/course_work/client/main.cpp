#include "client.h"
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "console.h"
#include "configuration_manager.h"
#include "enums.h"
#include "client_controller.h"
#include "interface.h"

Client* Configure(QObject* parent, const ConfigurationManager& confManag, char tun);
bool ConnectToHost(Client* client, const ConfigurationManager& confManag, char tun);
QJsonDocument SettingsFile(QString name = "test");
void InterfaceThread(ClientController* controller);
QMap<QString, int> ConfigureCommandsDictionary();

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
  ClientController* cl_cont = new ClientController(client);
  std::thread thr(InterfaceThread, cl_cont);
  thr.detach();

  return a.exec();
}

void InterfaceThread(ClientController* controller)
{
  QString inp;
  Interface facade(controller);
  QMap<QString, int> command = ConfigureCommandsDictionary();

  while (inp != "exit")
  {
    cin >> inp;
    cin >> inp;

    switch (command[inp])
    {
    case 0:
      facade.GetListOfFilesReq();
      break;
    default:
      cout << "nothing__" << endl;
      break;
    }
  }
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
  settings.insert("command", UPLOAD_FILE);
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

QMap<QString, int> ConfigureCommandsDictionary()
{
  QMap<QString, int> dict;
  dict.insert("get files", 0);
  return dict;
}







