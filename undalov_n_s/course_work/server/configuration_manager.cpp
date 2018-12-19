#include "configuration_manager.h"

ConfigurationManager::ConfigurationManager(QString path)
{
    path_ = path;
}



QString ConfigurationManager::GetValue(QString key) const {
    QFile f(path_);
    if (!f.open(QIODevice::ReadOnly)){
       throw std::exception("can not open configuration file");
    }
    QJsonObject config = QJsonDocument::fromJson(f.readAll()).object();  
    if(config[key].isNull()){
        QString message = "can not find value: ";
        throw std::exception(message.append(key).toStdString().c_str());
    }
    return config[key].toString();
}

