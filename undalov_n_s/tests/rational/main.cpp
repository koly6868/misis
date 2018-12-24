 #include <iostream>
#include <sstream>
#include "../../prj.labs/rational/rational.h"



using namespace std;

int main()
{
	Rational r = Rational(2,4);
	Rational r1 = Rational(3,5);
	cout << "TEST CONSTRUCTORS" << endl;

  cout << "Rational()"<< endl;
  cout << Rational() << endl;

  cout << "Rational(1,2)" << endl;
  cout << Rational(1,2) << endl;

  cout << "Rational(3/5)" << endl;
  cout << Rational(Rational(3,5)) << endl;
  
  cout << "Rational(-1,2)" << endl;
  cout << Rational(-1, 2) << endl;

  cout << "Rational(1,-2)" << endl;
  cout << Rational(1, -2) << endl;

  cout << "Rational(-1,-2)" << endl;
  cout << Rational(-1, -2) << endl;

  cout << "Rational(2,4)" << endl;
  cout << Rational(2, 4) << endl;

	cout << "Call constructor with 0 denominator" << endl;
	try
	{
	  cout << Rational(2,0);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
  cout << "TEST BOOL LOGICK" << endl;
  cout << "2/5 == 2/5" << endl;
  cout << (Rational(2,5) == Rational(2,5)) << endl;

  cout << "2/5 == 1/5" << endl;
  cout << (Rational(2, 5) == Rational(1, 5)) << endl;

  cout << "2/5 != 2/5" << endl;
  cout << (Rational(2, 5) != Rational(2, 5)) << endl;

  cout << "2/5 != 1/5" << endl;
  cout << (Rational(2, 5) != Rational(1, 5)) << endl;

	cout << "TSET ARITHMETIC" << endl;
	cout << "2/4 + 3/5 == " << r + r1 << endl;
	cout << "2/4 - 3/5 == " << r - r1 << endl;
	cout << "2/4 * 3/5 == " << r * r1 << endl;
	cout << "2/4 / 3/5 == " << r / r1 << endl;
  cout << "2/4 = 3/5 == " << (r = r1) << endl;
  cout << "2/4 += 3/5 == " << (Rational(2,4) += Rational(3,5)) << endl;
  cout << "2/4 -= 3/5 == " << (Rational(2, 4) -= Rational(3, 5)) << endl;
  cout << "2/4 *= 3/5 == " << (Rational(2, 4) *= Rational(3, 5)) << endl;
  cout << "2/4 /= 3/5 == " << (Rational(2, 4) /= Rational(3, 5)) << endl;
  cout << "2/4 = 3/5 = 2/7 ==" << (Rational(2,4) = Rational(3,5) = Rational(2,7)) << endl;

  cout << endl << endl;
  Rational lhs(1,1);
  Rational rhs(2,3);
  cout << "test "<< lhs << " = " << rhs << endl;
  cout << (lhs = rhs) << endl;
	
}


