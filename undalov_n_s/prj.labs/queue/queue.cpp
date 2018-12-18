#include "queue.h"


Queue::Queue(int size)
  : size_(size + 1)
{
  data_ = new int[size_];
}



Queue::Queue(const Queue & obj)
  : size_(obj.size_)
  , head_(obj.head_),
  tail_(obj.tail_)
{
  data_ = new int[size_];
  for (int i = 0; i < size_; i++)
  {
    data_[i] = obj.data_[i];
  }
}



Queue::~Queue()
{
  delete[] data_;
}



bool Queue::IsEmpty() const
{
  return head_ == tail_;
}



bool Queue::IsFull() const
{
  return head_ == (tail_ + 1) % size_;
}



int Queue::Top() const
{
  if (IsEmpty()) throw std::out_of_range("empty");
  return data_[head_];
}



int Queue::Pop()
{
  if (IsEmpty()) throw std::out_of_range("empty");
  int res = data_[head_];
  head_ = (head_ + 1) % size_;
  return res;
}



void Queue::Push(int value)
{
  if (IsFull()) throw std::out_of_range("full");
  data_[tail_] = value;
  tail_ = (tail_ + 1) % size_;
}

std::ostream& Queue::WriteTo(std::ostream & strm) const
{
  if (size_ != 1)
  {
    strm << '{';
    int i = head_;
    while (i != tail_)
    {
      strm << data_[i];
      i = (i + 1) % size_;
      if (tail_ == (i + 1) % size_)
      {
        strm << ", ";
      }
    }
    strm << '}';
  }
  return strm;
}



Queue& Queue::operator=(const Queue & rhs)
{
  if (this != &rhs)
  {
    if (rhs.size_ > size_)
    {
      int * new_data = new int[rhs.size_];
      delete[] data_;
      data_ = new_data;
    }
    size_ = rhs.size_;
    head_ = rhs.head_;
    tail_ = rhs.tail_;
    int i = head_;
    while (i != tail_)
    {
      data_[i] = rhs.data_[i];
      i = (i + 1) % size_;
    }
  }
  return *this;
}

std::ostream & operator<<(std::ostream & strm, Queue & q)
{
  return q.WriteTo(strm);
}
