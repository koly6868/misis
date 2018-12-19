#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <QtCore>



using namespace std;
istream& operator>>(istream& stream, QString& str){
    string input;
    stream >> input;
    str = QString(input.c_str());
    return stream;
}



istream& operator>>(istream& stream, QByteArray& array){
    string input;
    stream >> input;
    array = QByteArray(input.c_str());
    return stream;
}



ostream& operator<<(ostream& stream, const QString& str){
    stream << str.toStdString();
    return stream;
}



ostream& operator<<(ostream& stream, const QByteArray& array){
    stream << array.toStdString();
    return stream;
}

#endif // CONSOLE_H
