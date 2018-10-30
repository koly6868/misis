 #include <iostream>
#include <sstream>
#include "rational.h"



using namespace std;

int main()
{
	Rational r = Rational(2,4);
	Rational r1 = Rational(3,5);
	
	cout << "Call constructor with 0 denominator" << endl;
	try
	{
	cout << Rational(2,0);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
	cout << "2/4 + 3/5 = " << r + r1 << endl;
	cout << "2/4 - 3/5 = " << r - r1 << endl;
	cout << "2/4 * 3/5 = " << r * r1 << endl;
	cout << "2/4 * -3/5 = " << r * Rational(-3,5) << endl;
	cout << "2/4 * 3/-5 = " << r * Rational(3,-5) << endl;
	cout << "2/4 * -3/-5 = " << r * Rational(-3,-5) << endl;

	cout << "2/4 / 3/5 = " << r / r1 << endl;
	
}


