#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <math.h>
#include <iostream>

class PriorityQueue
{
public:
  ~PriorityQueue();
  PriorityQueue();
  PriorityQueue(int size);
  PriorityQueue(const PriorityQueue& q);
  int pop();
  void push(int val, int priority);
  int top() const;
  bool isEmpty() const;
  bool isFull() const;
  int size() const;
  PriorityQueue& operator=(const PriorityQueue& q);
  std::ostream& writeTo(std::ostream& strm) const;

private:
  struct Node
  {
  public:
    int data{ 0 };
    int priority{ 0 };
  };

  int searchPlace(int priority) const;

private:
  Node* data_{ nullptr };
  int size_{ 2 };
  int head_{ 0 };
  int tail_{ 0 };
};



std::ostream& operator<<(std::ostream& strm, const PriorityQueue& q);

#endif // !PRIORITY_QUEUE_H
