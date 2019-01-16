#include "priority_queue.h"


PriorityQueue::PriorityQueue(const PriorityQueue & q)
  : size_(q.size_)
  , head_(q.head_)
  , tail_(q.tail_)
{
  data_ = new Node[size_];
  int i = head_;
  while (i != tail_)
  {
    data_[i].data = q.data_[i].data;
    data_[i].priority = q.data_[i].priority;
    i = (i + 1) % size_;
  }
}



PriorityQueue::~PriorityQueue()
{
  while (!isEmpty())
  {
    pop();
  }
}



PriorityQueue::PriorityQueue()
{
  data_ = new Node[2];
}

PriorityQueue::PriorityQueue(int size)
  : size_(size + 1)
{
  if (size <= 0) throw std::exception("size must be positive");
  data_ = new Node[size_];
}



void PriorityQueue::pop()
{
  if (!isEmpty())
  {
    head_ = (head_ + 1) % size_;
  }
}



void PriorityQueue::push(int val, int priority)
{
  if (isFull()) throw std::exception("full");
  if (isEmpty())
  {
    data_[tail_] = { val, priority };
    tail_ = (tail_ + 1) % size_;
  }
  else
  {
    int index = searchPlace(priority);
    int i = tail_;
    while (i != index)
    {
      data_[i] = data_[i - 1];
      i = (i - 1 + size_) % size_;
    }
    data_[index] = { val, priority };
    tail_ = (tail_ + 1) % size_;
  }
}



int PriorityQueue::top() const
{
  if (isEmpty()) throw std::exception("empty");
  return data_[head_].data;
}



bool PriorityQueue::isEmpty() const
{
  return head_ == tail_;
}



bool PriorityQueue::isFull() const
{
  return head_ == ((tail_ + 1) % size_);
}

int PriorityQueue::size() const
{
  return size_ - 1;
}



PriorityQueue & PriorityQueue::operator=(const PriorityQueue & q)
{
  if (this != &q)
  {
    if (q.size_ > size_)
    {
      delete[] data_;
      data_ = new Node[q.size_];
    }
    head_ = q.head_;
    tail_ = q.tail_;
    size_ = q.size_;

    int i = head_;
    while (i != tail_)
    {
      data_[i].data = q.data_[i].data;
      data_[i].priority = q.data_[i].priority;
      i = (i + 1) % size_;
    }
  }
  return *this;
}



std::ostream & PriorityQueue::writeTo(std::ostream & strm) const
{
  if (strm.good())
  {
    strm << '{';
    int i = head_;
    while (i != tail_)
    {
      strm << data_[i].data;
      i = (i + 1) % size_;
      if (i != tail_)
      {
        strm << ", ";
      }
    }
    strm << '}';
  }
  return strm;
}



int PriorityQueue::searchPlace(int priority) const
{
  int index = 0;
  int a = head_;
  int b = tail_;
  int dif;
  int mid;

  while (abs(a - b) != 1)
  {
    dif = b - a;
    if (dif >= 0)
    {
      mid = (a + dif / 2) % size_;
    }
    else
    {
      mid = (a + (size_ + dif)) % size_;
    }

    if (data_[mid].priority == priority)
    {
      return mid + 1;
    }
    else
    {
      if (data_[mid].priority > priority)
      {
        a = mid;
      }
      else
      {
        b = mid;
      }
    }
  }

  if (data_[a].priority == priority)
  {
    return a + 1;
  }
  else
  {
    if (data_[a].priority > priority)
    {
      return a + 1;
    }
    else
    {
      return a;
    }
  }
}



std::ostream& operator<<(std::ostream& strm, const PriorityQueue& q)
{
  return q.writeTo(strm);
}
