#include "stack.h"
#include <iostream>

int main()
{
	using namespace std;
	typedef int T;
  cout << "test Stcak<T>()" << endl;
  Stack<T> s;
  cout << "test push(1)" << endl;
  s.push(T(1));
  cout << "test Stack<T>(s) where s is privious stack" << endl;
  Stack<T>s2(s);
  cout << "test Stcak<T> a = s" << endl;
  Stack<T> a = s;
  cout << "test s2.pop()" << endl;
  cout << s2.pop() << endl;
  cout << "test s.pop()" << endl;
  cout << s.pop() << endl;
  cout << "test a.pop()" << endl;
  cout << a.pop()<< endl;
  cout << "test a.pop() when a is empty" << endl;
  try
  {
    a.pop();
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }



	return 0;
}