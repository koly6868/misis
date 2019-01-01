#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class PriorityQueue
{
public:
  PriorityQueue();
  ~PriorityQueue();

private:
  struct Node
  {
  public:
    int data{ 0 };
    int priority{ 0 };
  };

  Node* data_{ nullptr };
  int size_;
  int end_;
};


#endif // !PRIORITY_QUEUE_H
