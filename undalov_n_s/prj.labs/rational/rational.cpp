#include <stdexcept>

#include "rational.h"




	using namespace std;

	Rational::Rational(int num, int den)
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

	Rational& Rational::operator+=(Rational& r)
	{
		int nod = Nod(r.denominator, denominator);
		numerator = numerator * r.denominator / nod + r.numerator * denominator / nod;
		denominator = denominator * r.denominator / nod;
		Reduction(numerator, denominator);
		return *this;
	}
	Rational& Rational::operator-=(Rational& r)
	{
		int nod = Nod(r.denominator, denominator);
		numerator = numerator * r.denominator / nod - r.numerator * denominator / nod;
		denominator = denominator * r.denominator / nod;
		Reduction(numerator, denominator);
		return *this;
	}
	Rational& Rational::operator*=(Rational& r)
	{
		numerator *= r.numerator;
		denominator *= r.denominator;
		Reduction(numerator, denominator);
		return *this;
	}
	Rational& Rational::operator/=(Rational& r)
	{
		numerator *= r.denominator;
		denominator *= r.numerator;
		Reduction(numerator, denominator);
		return *this;
	}
	Rational Rational::operator+(Rational& r)
	{
		Rational a = *this;
		a += r;
		return a;
	}
	Rational Rational::operator-(Rational& r)
	{
		Rational a = *this;
		a -= r;
		return a;
	}
	Rational Rational::operator*(Rational& r)
	{
		Rational a = *this;
		a *= r;
		return a;
	}
	Rational Rational::operator/(Rational& r)
	{
		Rational a = *this;
		a /= r;
		return a;
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
			Reduction(num,den);
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
	