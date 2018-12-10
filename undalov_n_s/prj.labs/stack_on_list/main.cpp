#include "stack.h"
#include <iostream>

int main()
{
	using namespace std;
	Stack<int> s = Stack<int>();
  s.push(1);
  s.push(2);
   Stack<int> s2 = Stack<int>(s);
  cout << s2.pop();
	return 0;
}