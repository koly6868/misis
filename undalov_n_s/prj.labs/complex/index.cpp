// Copyright 2018 by Polevoy Dmitry under Free Public License 1.0.0

#include <iostream>
#include "complex.h"

bool testParse(const std::string& str) {
  using namespace std;
  istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str << " -> " << z << endl;
  } else {
    cout << "Read error : " << str << " -> " << z << endl;
  }
  return istrm.good();
}

int main() {
  using namespace std;

  Complex z;
  z += Complex(8.0);
  testParse("{8.9,9}");
  testParse("{8.9, 9}");
  testParse("{8.9,9");

  Complex first = Complex(1,2);
  Complex second = Complex(3,5);

  cout << "check + , expected answer {4,7}" << endl;
  cout << "{1,2} + {3,5} = " << first + second << endl << endl;

  cout << "check - , expected answer {-2,-3}" << endl;
  cout << "{1,2} - {3,5} = " << first - second << endl << endl;

  cout << "check * , expected answer {-7,11}" << endl;
  cout << "{1,2} * {3,5} = " << first * second << endl << endl;

  cout << "check / , expected answer {0.382353,0.0294118}" << endl;
  cout << "{1,2} / {3,5} = " << first / second << endl << endl;

  cout << "check = , expected answer {3,5}" << endl;
  cout << "{1,2} = {3,5} = " << (first = second) << endl << endl;

  cout << "check += , expected answer {4,7}" << endl;
  cout << "{1,2} += {3,5} = " << (Complex(1,2) += second) << endl << endl;

  cout << "check -= , expected answer {-2,-3}" << endl;
  cout << "{1,2} -= {3,5} = " << (Complex(1, 2) -= second) << endl << endl;

  cout << "check *= , expected answer {-7,11}" << endl;
  cout << "{1,2} *= {3,5} = " << (Complex(1, 2) *= second) << endl << endl;

  cout << "check /= , expected answer {0.382353,0.0294118}" << endl;
  cout << "{1,2} /= {3,5} = " << (Complex(1, 2) /= second) << endl << endl;
  return 0;
}

