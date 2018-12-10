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
    };
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
  Node<T>* head__{ nullptr };
};

template<typename T>
inline T& Stack<T>::pop()
{
  if (head__ == nullptr) throw std::out_of_range("empty");
  T res = head__->data_;
  head__ = head__->nextNode_;
  return res;
}

template<typename T>
inline void Stack<T>::push(const T & data)
{
  Node<T>* newNode = new Node<T>();
  newNode->data_ = data;
  newNode->nextNode_ = head__;
  head__ = newNode;
}



template<typename T>
Stack<T>::Stack(const Stack<T>& obj) : Stack<T>()
{
  head__ = new Node<T>(obj.head__);
  Node<T>* current_this = head__;
  Node<T>* current_copy = obj.head__->nextNode_;
  while (current_copy != nullptr)
  {
    current_this->nextNode_ = new Node<T>(current_copy);
    current_this = current_this->nextNode_;
    current_copy = current_copy->nextNode_;
  }
};

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
  if (this != &obj)
    *this = Stack(obj);
  return *this;
}
#endif // !Stack_2018



