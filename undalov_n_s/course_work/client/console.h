#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <QtCore>

using namespace std;
istream& operator>>(istream& stream, QString& str);
istream& operator>>(istream& stream, QByteArray& array);
ostream& operator<<(ostream& stream, const QString& str);
ostream& operator<<(ostream& stream, const QByteArray& array);
#endif // CONSOLE_H
