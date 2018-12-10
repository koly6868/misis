#ifndef RATIONAL_2018
#define RATIONAL_2018

#include <sstream>


class Rational
{
public:
	Rational() = default;
  ~Rational() = default;
  Rational(const Rational& r);
	Rational(const int num, const int den);
  Rational& operator=(const Rational& r);
	bool operator==(const Rational& r);
	bool operator!=(const Rational& r);
	Rational& operator+=(const Rational& r);
	Rational& operator-=(const Rational& r);
	Rational& operator*=(const Rational& r);
	Rational& operator/=(const Rational& r);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int numerator{ 0 };
	int denominator{ 1 };
	static const char del = '/';
	int Nod(int, int);
	void Reduction(int&, int&);
};


Rational operator+(const Rational& l, const Rational& r);



Rational operator-(const Rational& l, const Rational& r);



Rational operator*(const Rational& l, const Rational& r);



Rational operator/(const Rational& l, const Rational& r);



inline std::ostream& operator<<(std::ostream& ostrm, const Rational& r)
{
	return r.writeTo(ostrm);
}



inline std::istream& operator>>(std::istream& istrm, Rational& r)
{
	return r.readFrom(istrm);
}
#endif // !RATIONAL_2018

