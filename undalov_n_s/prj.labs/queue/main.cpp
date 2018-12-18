#include "queue.h"
#include <iostream>
void Test()
{
  using namespace std;
  cout << "test Queue(2)" << endl;
  Queue q(2);
  cout << "call Push and write queue" << endl;
  q.Push(2);
  cout << q << endl;
  cout << "call top and write queue"<< endl;
  cout << q.Top() << endl;
  cout << "call IsEmpty on {2} with size 2" << endl;
  cout << q.IsEmpty() << endl;
  cout << "test Pop" << endl;
  cout << q.Pop() << endl;
  cout << "call IsEmpty on {} with size 2" << endl;
  cout << q.IsEmpty() << endl;
  cout << "test IsFull on {1,2} with size 2" << endl;
  q.Push(1);
  q.Push(2);
  cout << q.IsFull() << endl;
  cout << "test IsFull on {2} with size 2" << endl;
  q.Pop();
  cout << q.IsFull() << endl;
  cout << "test Queue({2})" << endl;
  Queue a(q);
  cout << a << endl;
  q.Push(10);
  cout << "test {2} = {2,10}" << endl;
  cout << (a = q) << endl;


}

int main()
{
  Test();
  return 0;
}