#include <iostream>
#include "../../prj.labs/priority_queue/priority_queue.h"

void Test();



int main()
{
  Test();
  return 0;
}



void Test()
{
  using namespace std;
  cout << "test PriorityQueue(3)" << endl;
  PriorityQueue q1(3);
  cout << "size: " <<  q1.size() << endl;
  cout << "push value 1 with priority 0" << endl;
  q1.push(1,0);
  cout << q1 << endl;

  cout << "push value 32 with priority 12" << endl;
  q1.push(32, 12);
  cout << q1 << endl;

  cout << "push value 3 with priority -12" << endl;
  q1.push(3, -12);
  cout << q1 << endl;
  
  cout << "pop()" << endl;
  cout << q1.pop() << endl;
  cout << q1 << endl;

  cout << "isFull()" << endl;
  cout << q1.isFull() << endl;
  cout << "isEmpty()" << endl;
  cout << q1.isEmpty() << endl;

  cout << "PriorityQueue({1,3})" << endl;
  cout << PriorityQueue(q1) << endl;

  cout << "PriorityQueeu()" << endl;
  PriorityQueue q2;

  cout << "isFull()" << endl;
  cout << q2.isFull() << endl;
  cout << "isEmpty()" << endl;
  cout << q2.isEmpty() << endl;
  cout << "{} = {1, 3}" << endl;
  cout << (q2 = q1) << endl;

  cout << "push value 10 with priority -12" << endl;
  q2.push(10, -12);
  cout << q2 << endl;

  cout << "isFull()" << endl;
  cout << q2.isFull() << endl;
  cout << "isEmpty()" << endl;
  cout << q2.isEmpty() << endl;

  cout << "top()" << endl;
  cout << q2.top() << endl;

  cout << "push value in full queue" << endl;
  try
  {
    q2.push(1,1);
    cout << "error" << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }

  cout << "pop value from empty stack" << endl;
  try
  {
    PriorityQueue().pop();
    cout << "error" << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }

  cout << "PriorityQueue(-1)" << endl;
  try
  {
    PriorityQueue(-1);
    cout << "error" << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }
}