#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <QtCore>
class ConfigurationManager
{
public:
  ConfigurationManager(QString schema = "default", QString path = "config.json");
  QString GetValue(QString key) const;
  bool IsValid() const;
  void SaveConfig(QString name, QString ip, quint16 port, QString storagePath = ".\\files");
  QString ConfigList();
private:
  QString path_{ "config.json" };
  QString schema_{ "default" };
};

#endif // CONFIGURATIONMANAGER_H
