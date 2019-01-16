#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <QtCore>
class ConfigurationManager
{
public:
  ConfigurationManager(QString schema = "default", QString path = "config.json");
//получить значение из конфига 
  QString GetValue(QString key) const;
//проверка на валидность конфига
  bool IsValid() const;
//сохранить изменеия конфига
  void SaveConfig(QString name, QString ip, quint16 port, QString storagePath = ".\\files");
//список конфигураций
  QString ConfigList();

private:
  QString path_{ "config.json" };
  QString schema_{ "default" };
};
#endif //CONFIGURATIONMANAGER_H