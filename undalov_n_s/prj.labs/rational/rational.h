#ifndef Rational_2018
#define Rational_2018

#include <sstream>


class Rational
{
public:
	Rational() = default;
	Rational(int num, int den);
	bool operator==(Rational& r) { return (numerator == r.numerator) && (denominator == r.denominator); }
	bool operator!=(Rational& r) { return !operator==(r); }
	Rational& operator+=(Rational& r);
	Rational& operator-=(Rational& r);
	Rational& operator*=(Rational& r);
	Rational& operator/=(Rational& r);
	Rational operator+(Rational& r);
	Rational operator-(Rational& r);
	Rational operator*(Rational& r);
	Rational operator/(Rational& r);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int numerator{ 0 };
	int denominator{ 0 };
	static const char del = '/';
	int Nod(int, int);
	void Reduction(int&, int&);
};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& r)
{
	return r.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& r)
{
	return r.readFrom(istrm);
}

#endif // !Rational_2018

