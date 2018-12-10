#ifndef Stack_2018
#define Stack_2018

#include <stdexcept>

template<typename T>
class Stack
{
  template<typename T>
  struct Node
  {
  public:
    Node() = default;
    Node(const Node<T>* node) : Node()
    {
      data_ = node->data_;
      nextNode_ = node->nextNode_;
    }
    Node<T>* nextNode_{ nullptr };
    T data_;
  };
public:
  Stack() = default;
  Stack(const Stack<T>& obj);
  Stack<T>& operator=(const Stack<T>& obj); 
  T& pop();
  void push(const T& data);
private:
  Node<T>* head_{ nullptr };
  Node<T>* last_{ nullptr };
};

template<typename T>
inline T& Stack<T>::pop()
{
  if (head_ == nullptr) throw std::out_of_range("empty");
  T res = last_->data_;
  last_ = last_->nextNode_;
  return res;
}

template<typename T>
inline void Stack<T>::push(const T & data)
{
  Node<T>* newNode = new Node<T>();
  newNode->data_ = data;
  if (head_ == nullptr)
  {
    head_ = newNode;
    last_ = head_;
  }
  else
  {
    Node<T>* p = last_;
    last_ = newNode;
    last_->nextNode_ = p;
  }
}



template<typename T>
Stack<T>::Stack(const Stack<T>& obj) : Stack<T>()
{
  head_ = new Node<T>(obj.head_);
  last_ = new Node<T>(obj.last_);
  if (obj.head_ != obj.last_) last_->nextNode_ = head_;
  if (!((head_ == last_) || (last_->nextNode_ == head_)))
  {
    Node<T>* current_copy = head_->nextNode_;
    Node<T>* current_this = last_;
    while (current_copy->nextNode_ != nullptr)
    {
      current_this->nextNode_ = new Node<T>(current_copy);
      current_this = current_this->nextNode_;
      current_copy = current_copy->nextNode_;
    }
  }
};

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
  this = new Stack(obj);
  return *this;
}
#endif // !Stack_2018

