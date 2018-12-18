#include <stdexcept>
#include <math.h>
#include "rational.h"

using namespace std;



Rational operator+(const Rational& l, const Rational& r)
{
  return Rational(l) += r;
}



Rational operator-(const Rational& l, const Rational& r)
{
  return Rational(l) -= r;
}



Rational operator*(const Rational& l, const Rational& r)
{
  return Rational(l) *= r;
}



Rational operator/(const Rational& l, const Rational& r)
{
  return Rational(l) /= r;
}


bool Rational::operator==(const Rational& r)
{
  return abs(numerator - r.numerator) < std::numeric_limits<double>::epsilon()
    && abs(denominator - r.denominator) < std::numeric_limits<double>::epsilon();
}



bool Rational::operator!=(const Rational& r)
{
  return !operator==(r);
}



Rational::Rational(const Rational & r)
  :Rational(r.numerator, r.denominator)
{
}



Rational::Rational(const int num, const int den)
{
  if (den == 0) throw invalid_argument("Denominator can not be 0");
  if (den < 0)
  {
    numerator = -num;
    denominator = -den;
  }
  else
  {
    numerator = num;
    denominator = den;
  }

  Reduction(numerator, denominator);
}



Rational& Rational::operator=(const Rational & r)
{
  if (&r != this)
  {
    numerator = r.numerator;
    denominator = r.denominator;
  }
  return *this;
}



Rational& Rational::operator+=(const Rational& r)
{
  int nod = Nod(r.denominator, denominator);
  numerator = numerator * r.denominator / nod + r.numerator * denominator / nod;
  denominator = denominator * r.denominator / nod;
  Reduction(numerator, denominator);
  return *this;
}



Rational& Rational::operator-=(const Rational& r)
{
  int nod = Nod(r.denominator, denominator);
  numerator = numerator * r.denominator / nod - r.numerator * denominator / nod;
  denominator = denominator * r.denominator / nod;
  Reduction(numerator, denominator);
  return *this;
}



Rational& Rational::operator*=(const Rational& r)
{
  numerator *= r.numerator;
  denominator *= r.denominator;
  Reduction(numerator, denominator);
  return *this;
}



Rational& Rational::operator/=(const Rational& r)
{
  numerator *= r.denominator;
  denominator *= r.numerator;
  Reduction(numerator, denominator);
  return *this;
}



std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
  ostrm << numerator << "/" << denominator;
  return ostrm;
}



std::istream& Rational::readFrom(std::istream& istrm)
{
  char a;
  int num;
  int den;
  istrm >> num >> a >> den;

  if (a == Rational::del)
  {
    Reduction(num, den);
    numerator = num;
    denominator = den;
  }
  else
  {
    istrm.setstate(std::ios_base::failbit);
  }
  return istrm;
}



int Rational::Nod(int a, int b)
{
  a = abs(a);
  b = abs(b);
  while (a != b)
  {
    if (a > b)
    {
      a -= b;
    }
    else
    {
      b -= a;
    }
  }
  if (!a) a = 1;
  return a;
};



void Rational::Reduction(int& a, int& b)
{
  int red = Nod(a, b);
  if (!red) return;
  a /= red;
  b /= red;
};
