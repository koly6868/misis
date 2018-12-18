#include "stack.h"
#include <iostream>

void Test()
{
  using namespace std;
  typedef int T;
  cout << "test Stcak<T>()" << endl;
  Stack<T> s;
  cout << "test push(1)" << endl;
  s.Push(T(1));
  cout << "test Stack<T>(s) where s is privious stack" << endl;
  Stack<T>s2(s);
  cout << "test Stcak<T> a = s" << endl;
  Stack<T> a;
  a.Push(1);
  a.Push(2);
  a = s;
  cout << "test s2.pop()" << endl;
  cout << s2.Pop() << endl;
  cout << "test s.pop()" << endl;
  cout << s.Pop() << endl;
  cout << "test a.pop()" << endl;
  cout << a.Pop() << endl;
  cout << "test a.pop() when a is empty" << endl;
  try
  {
    a.Pop();
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }
  cout << "call is_empty()" << endl;
  cout << a.IsEmpty() << endl;
  Stack<T>t;
  t.Push(2);
  t.Push(4);
  cout << "Stack : {4,2}" << endl;
  cout << "call Top()" << endl;
  cout << t.Top() << endl;
  cout << "test \'<<\' "<< endl;
  cout << t;
  cout << "call Clear()" << endl;
  t.Clear();
  cout << t << endl;
}



int main()
{
	Test();
	return 0;
}