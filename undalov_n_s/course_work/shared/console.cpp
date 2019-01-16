#include "console.h"

istream& operator>>(istream& stream, QString& str)
{
  string input;
  stream >> input;
  str = QString(input.c_str());
  return stream;
}



istream& operator>>(istream& stream, QByteArray& array)
{
  string input;
  stream >> input;
  array = QByteArray(input.c_str());
  return stream;
}



ostream& operator<<(ostream& stream, const QString& str)
{
  stream << str.toStdString();
  return stream;
}



ostream& operator<<(ostream& stream, const QByteArray& array)
{
  stream << array.toStdString();
  return stream;
}