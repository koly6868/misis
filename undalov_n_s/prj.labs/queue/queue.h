#ifndef QUEUE_2018
#define QUEUE_2018
#include <iostream>

class Queue
{
public:
  Queue() = default;
  explicit Queue(int size);
  Queue(const Queue &obj);
  ~Queue();
  bool IsEmpty() const;
  bool IsFull() const;
  int Top() const;
  int Pop();
  void Push(int value);
  std::ostream& WriteTo(std::ostream& strm) const;
  Queue &operator=(const Queue &rhs);

private:
  int *data_{ nullptr };
  int size_{ 1 };
  int head_{ 0 };
  int tail_{ 0 };
};

std::ostream& operator<<(std::ostream& strm, Queue& q);


#endif // !QUEUE_2018
