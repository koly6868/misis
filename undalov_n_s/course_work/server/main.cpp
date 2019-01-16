#include <QCoreApplication>
#include "server.h"
#include <QTcpSocket>
#include <iostream>
#include "configuration_manager.h"
#include "../shared/console.h"

QString ReadIP();
int ReadPositiveValue();



int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication app(argc, argv);
  ConfigurationManager configManag;
  QString input;
  quint16 port;
  QString ip;
  FileTcpServer* server;

  cout << "use default settings? yes, no" << endl;
  while (true)
  {
    cin >> input;
    if (input == "yes")
    {
      cout << "configs: " << configManag.ConfigList() << endl;
      QString config_name;
      cout << "Enter name of configuration" << endl;
      while (true)
      {
        cin >> config_name;
        configManag = ConfigurationManager(config_name);
        if (configManag.IsValid())
        {
          ip = configManag.GetValue("ip");
          port = configManag.GetValue("port").toInt();
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

      QString answ;
      cout << "save settings? yes, no" << endl;
      while (true)
      {
        cin >> answ;
        if (answ == "yes")
        {
          cout << "enter name of config" << endl;
          cin >> answ;
          configManag.SaveConfig(answ, ip, port);
            break;
        }
        if (answ == "no")
        {
          break;
        }
        cout << "uncorrect answer" << endl;
      }
      break;
    }
    cout << "ucncorrect answer, try again" << endl;
  }
  server = new FileTcpServer(&app, port, QHostAddress(ip), configManag.GetValue("storagePath"));


  return app.exec();
}



int ReadPositiveValue()
{
  QString val;
  while (true)
  {
    std::cin >> val;
    if (val.toInt() <= 0)
    {
      std::cout << "value have to be positive" << endl;
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
    std::cin >> ip;
    list = ip.split(".");
    if (list.size() != 4)
    {
      std::cout << "uncorrect ip" << endl;
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      list[i].toUInt(&ok);
      if (!ok)
      {
        std::cout << "uncorrect ip" << endl;
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
