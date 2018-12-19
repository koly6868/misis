#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <QtCore>
class ConfigurationManager
{
public:
    ConfigurationManager(QString path = "config.json");
    QString GetValue(QString key) const;
private:
    QString path_{"config.json"};
};

#endif // CONFIGURATIONMANAGER_H
