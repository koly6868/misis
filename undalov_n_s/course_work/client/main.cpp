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
void InterfaceThread(ClientController* controller);
QMap<QString, int> ConfigureCommandsDictionary();
int ReadPositiveValue();
QString ReadIP();


int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication app(argc, argv);
  ConfigurationManager confManag;
  quint16 port;
  quint16 server_port;
  QString ip;
  QString server_ip;
  Client* client;
  ClientController* cl_cont;
  QString input;

  cout << "use default settings? yes, no" << endl;
  while (true)
  {
    cin >> input;
    if (input == "yes")
    {
      QString config_name;
      cout << "Enter name of configuration" << endl;
      while (true)
      {
        cin >> config_name;
        confManag = ConfigurationManager(config_name);
        if (confManag.IsValid())
        {
          ip = confManag.GetValue("ip");
          port = confManag.GetValue("port").toInt();
          server_ip = confManag.GetValue("ipServer");
          server_port = confManag.GetValue("portServer").toInt();
          break;
        }
        else
        {
          cout << "unccorect name, try again (you may use \'default\' configuration)" << endl;
        }
      }
      break;
    }
    if (input == "no")
    {
      cout << "enter your adress" << endl;
      ip = ReadIP();
      cout << "enter port" << endl;
      port = ReadPositiveValue();
      cout << "enter host adress" << endl;
      server_ip = ReadIP();
      cout << "enter port" << endl;
      server_port = ReadPositiveValue();
      break;
    }
    cout << "ucncorrect answer, try again" << endl;
  }
  client = new Client(&app, port, QHostAddress(ip));
  client->ConnectToHost(QHostAddress(server_ip), server_port);
  cl_cont = new ClientController(client);
  std::thread thr(InterfaceThread, cl_cont);
  thr.detach();

  return app.exec();
}

void InterfaceThread(ClientController* controller)
{
  QString inp;
  QString fileName;
  Interface facade(controller);
  QMap<QString, int> command = ConfigureCommandsDictionary();
  QFile f(".\\info\\commands.txt");

  while (inp != "exit")
  {
    inp = "";
    cin >> inp;

    switch (command[inp])
    {
    case 0:
      cout << "unknown command" << endl;
      break;
    case 1:
      cout << "Enter a file name" << endl;
      cin >> fileName;
      facade.DownloadFileReq(fileName);
      break;
    case 2:
      cout << "Enter a file name" << endl;
      cin >> fileName;
      facade.UploadFileReq(fileName);
      break;
    case 3:
      cout << controller->GetListOfFiles() << endl;
      break;
    case 4:
      if (f.open(QIODevice::ReadOnly))
      {
        QString line;
        do
        {
          line = f.readLine();
          cout << line << endl;
        } while (line != "");
        f.close();
      }
      break;
    case 5:
      if (controller->IsConected())
      {
        cout << "conected" << endl;
      }
      else
      {
        cout << "unconected" << endl;
      }
      break;
    case 6:
      facade.GetListOfFilesReq();
      break;
    default:
      cout << "unknown command" << endl;
      break;
    }
  }
}



QMap<QString, int> ConfigureCommandsDictionary()
{
  QMap<QString, int> dict;
  dict.insert("files", 6);
  dict.insert("download", 1);
  dict.insert("upload", 2);
  dict.insert("storage", 3);
  dict.insert("help", 4);
  dict.insert("state", 5);
  return dict;
}



int ReadPositiveValue()
{
  QString val;
  while (true)
  {
    cin >> val;
    if (val.toInt() <= 0)
    {
      cout << "value have to be positive" << endl;
    }
    else
    {
      break;
    }
  }
  return val.toInt();
}



QString ReadIP()
{
  QString ip;
  QStringList list;
  bool ok;

  while (true)
  {
    cin >> ip;
    list = ip.split(".");
    if (list.size() != 4)
    {
      cout << "uncorrect ip" << endl;
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      list[i].toUInt(&ok);
      if (!ok)
      {
        cout << "uncorrect ip" << endl;
        continue;
      }
    }
    if (ok)
    {
      break;
    }
  }

  return ip;
}







