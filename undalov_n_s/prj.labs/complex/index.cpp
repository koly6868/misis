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
  cout << "TEST CONSTRUCTORS" << endl;
  
  cout << "Complex(1,2)" << endl;
  cout << Complex(1,2) << endl;

  cout << "Complex(1)" << endl;
  cout << Complex(1) << endl;

  cout << "Complex()" << endl;
  cout << Complex() << endl;

  cout << "Complex({1,2})" << endl;
  cout << Complex(Complex(1,2)) << endl;
  
  cout <<  "TEST BOOL LOGICK" << endl;
  cout << "{-1,2} == {-1,2}" << endl;
  cout << (Complex(-1,2) == Complex(-1,2)) << endl;

  cout << "{-1,2} == {2,2}" << endl;
  cout << (Complex(-1, 2) == Complex(2, 2)) << endl;

  cout << "{-1,2} != {-1,2}" << endl;
  cout << (Complex(-1, 2) != Complex(-1, 2)) << endl;

  cout << "{-1,2} == {2,2}" << endl;
  cout << (Complex(2, 2) != Complex(-1, 2)) << endl;

  cout << "TEST ARITHMETIC" << endl << "Both operand are Complex" << endl;
  cout << "check + , expected answer {4,7}" << endl;
  cout << "{1,2} + {3,5} = " << first + second << endl << endl;

  cout << "check - , expected answer {-2,-3}" << endl;
  cout << "{1,2} - {3,5} = " << first - second << endl << endl;

  cout << "check * , expected answer {-7,11}" << endl;
  cout << "{1,2} * {3,5} = " << first * second << endl << endl;

  cout << "check / , expected answer {0.382353,0.0294118}" << endl;
  cout << "{1,2} / {3,5} = " << first / second << endl << endl;

  cout << "check = , expected answer {1,2}" << endl;
  cout << "{1,2} = {1,2} = " << (first = first) << endl << endl;

  cout << "check = , expected answer {3,5}" << endl;
  cout << "{1,2} = {3,5} = " << (first = second) << endl << endl;

  cout << "check multi =, expected answer {1,4}" << endl;
  cout << "{1,2} = {3,5} = {1,4} == " << (Complex(1,2) = Complex(3, 5) = Complex(1, 4)) << endl << endl;

  cout << "check += , expected answer {4,7}" << endl;
  cout << "{1,2} += {3,5} = " << (Complex(1,2) += second) << endl << endl;

  cout << "check -= , expected answer {-2,-3}" << endl;
  cout << "{1,2} -= {3,5} = " << (Complex(1, 2) -= second) << endl << endl;

  cout << "check *= , expected answer {-7,11}" << endl;
  cout << "{1,2} *= {3,5} = " << (Complex(1, 2) *= second) << endl << endl;

  cout << "check /= , expected answer {0.382353,0.0294118}" << endl;
  cout << "{1,2} /= {3,5} = " << (Complex(1, 2) /= second) << endl << endl;

  cout << "One operand is Complex, another is double" << endl;

  cout << "check + , expected answer {2,2}" << endl;
  cout << "{1,2} + 1 = " << (Complex(1,2) + 1.0) << endl << endl;

  cout << "check - , expected answer {0,2}" << endl;
  cout << "{1,2} - 1 = " << Complex(1, 2) - 1.0 << endl << endl;

  cout << "check * , expected answer {2,4}" << endl;
  cout << "{1,2} * 2 = " << Complex(1, 2) * 2.0 << endl << endl;

  cout << "check / , expected answer {1,2}" << endl;
  cout << "{2,4} / 2 = " << Complex(2, 4) / 2.0 << endl << endl;

  cout << "check += , expected answer {2,2}" << endl;
  cout << "{1,2} += 1 = " << (Complex(1, 2) += 1) << endl << endl;

  cout << "check -= , expected answer {0,2}" << endl;
  cout << "{1,2} -= 1 = " << (Complex(1, 2) -= 1) << endl << endl;

  cout << "check *= , expected answer {2,4}" << endl;
  cout << "{1,2} *= 2 = " << (Complex(1, 2) *= 2) << endl << endl;

  cout << "check /= , expected answer {1,2}" << endl;
  cout << "{2,4} /= 2 = " << (Complex(2, 4) /= 2) << endl << endl;

  return 0;
}

