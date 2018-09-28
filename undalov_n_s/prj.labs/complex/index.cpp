// Copyright 2018 by Polevoy Dmitry under Free Public License 1.0.0

#include <iostream>
#include "Complex.h"

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
  return 0;
}


