 #include <iostream>
#include <sstream>
#include "rational.h"



using namespace std;

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


