#include "configuration_manager.h"

ConfigurationManager::ConfigurationManager(QString nameOfConfig, QString path)
{
  path_ = path;
  schema_ = nameOfConfig;
}



QString ConfigurationManager::GetValue(QString key) const
{
  QFile f(path_);
  if (!f.open(QIODevice::ReadOnly))
  {
    throw std::exception("can not open configuration file");
  }
  QJsonObject config = QJsonDocument::fromJson(f.readAll()).object().take(schema_).toObject();
  if (config.isEmpty())
  {
    throw std::exception("configuration is empty");
  }
  if (config[key].isNull())
  {
    throw std::exception("can not find value");
  }
  return config[key].toString();
}



bool ConfigurationManager::IsValid() const
{
  QFile f(path_);
  if (!f.open(QIODevice::ReadOnly))
  {
    return false;
  }
  QJsonObject config = QJsonDocument::fromJson(f.readAll()).object().take(schema_).toObject();
  if (config.isEmpty())
  {
    return false;
  }
  return true;
}



void ConfigurationManager::SaveConfig(QString name, QString ip, quint16 port, QString storagePath)
{
  QFile f(path_);
  if (!f.open(QIODevice::ReadOnly))
  {
    throw std::exception("can not open configuration file");
  }
  QJsonObject config = QJsonDocument::fromJson(f.readAll()).object();
  if (config.isEmpty())
  {
    throw std::exception("configuration is empty");
  }
  f.close();
  QJsonObject body_config;
  body_config.insert("ip", ip);
  body_config.insert("port", QString::number(port));
  body_config.insert("storagePath", storagePath);
  config.insert(name, body_config);
  f.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
  f.write(QJsonDocument(config).toJson());
}



QString ConfigurationManager::ConfigList()
{
  QFile f(path_);
  if (!f.open(QIODevice::ReadOnly))
  {
    throw std::exception("can not open configuration file");
  }
  QJsonObject config = QJsonDocument::fromJson(f.readAll()).object();
  return config.keys().join(", ");
}




