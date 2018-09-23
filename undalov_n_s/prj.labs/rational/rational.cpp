#include <iostream>;
#include <sstream>;
#include <cmath>;
using namespace std;

static int Nod(int a, int b)
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
			b-= a;
		}
	}
		if(!a) a = 1;
		return a;
};
static void Reduction(int& a, int&b)
{
	int red = Nod(a,b);
	if (!red) return;
	a /= red;
	b /= red;
};

class Rational
{
public:
	Rational() = default;
	Rational(int num, int den) 
	: numerator(num) 
	, denominator(den)
	{ }
	bool operator==(Rational& r) {return (numerator == r.numerator) && (denominator == r.denominator); }
	bool operator!=(Rational& r) {return !operator==(r); }
	Rational& operator+=(Rational& r)
		{ 
		int nod = Nod(r.denominator,denominator);
		numerator = numerator * r.denominator /nod + r.numerator * denominator /nod;
		denominator = denominator * r.denominator / nod;
		Reduction (numerator, denominator);
		return *this;
		}
	Rational& operator-=(Rational& r)
	{
		int nod = Nod(r.denominator, denominator);
		numerator = numerator * r.denominator / nod - r.numerator * denominator / nod;
		denominator = denominator * r.denominator / nod;
		Reduction(numerator, denominator);
		return *this;
	}
	Rational& operator*=(Rational& r)
	{
		numerator *=r.numerator;
		denominator *= r.denominator;
		Reduction(numerator, denominator);
		return *this;
	}
	Rational& operator/=(Rational& r)
	{
	numerator *= r.denominator;
	denominator *= r.numerator;
	Reduction(numerator, denominator);
	return *this;
	}
	Rational operator+(Rational& r)
	{
		Rational a = *this;
		a+=r;
		return a;
	}
	Rational operator-(Rational& r)
	{
		Rational a = *this;
		a -= r;
		return a;
	}
	Rational operator*(Rational& r)
	{
		Rational a = *this;
		a *= r;
		return a;
	}
	Rational operator/(Rational& r)
	{
		Rational a = *this;
		a /= r;
		return a;
	}
	std::ostream& writeTo(std::ostream& ostrm)
	{
		ostrm << numerator << "/" << denominator;
		return ostrm;
	}
	std::istream& readFrom(std::istream& istrm)
	{
		char a;
		int num;
		int den;
		istrm >> num >> a >> den;
		if (a == Rational::del)
		{
		numerator = num;
		denominator = den;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
		return istrm;
	}
	
	private:
	int numerator{0};
	int denominator{ 0 };
	static const char del ='/';
};

inline std::ostream& operator<<(std::ostream& ostrm, Rational r)
{
	return r.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& r)
{
	return r.readFrom(istrm);
}


int main()
{
	Rational r = Rational(2,4);
	Rational r1 = Rational(3,5);
	
	cout << "2/4 + 3/5 = " << r + r1 << endl;
	cout << "2/4 - 3/5 = " << r - r1 << endl;
	cout << "2/4 * 3/5 = " << r * r1 << endl;
	cout << "2/4 / 3/5 = " << r / r1 << endl;
	cin >> r;
	cout << r << endl;
	
	system("pause");
}


