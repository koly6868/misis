#ifndef STACK_2018
#define STACK_2018

#include <stdexcept>

template<typename T>
class Stack
{
public:
  Stack() = default;
  Stack(const Stack<T>& obj);
  ~Stack();
  Stack<T>& operator=(const Stack<T>& obj);
  T& Pop();
  T& Top() const;
  void Clear();
  void Push(const T& data);
  bool IsEmpty() const;
  std::ostream& WriteTo(std::ostream& ostrm) const;

private:
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

  Node<T>* head_{ nullptr };
};

template<typename T>
inline T& Stack<T>::Pop()
{
  if (IsEmpty())
  {
    throw std::out_of_range("empty");
  }
  T res = head_->data_;
  Node<T>* p = head_;
  head_ = head_->nextNode_;
  delete p;
  return res;
}



template<typename T>
inline T & Stack<T>::Top() const
{
  if (IsEmpty())
  {
    throw std::out_of_range("empty");
  }
  return head_->data_;
}



template<typename T>
inline void Stack<T>::Clear()
{
  while (!IsEmpty())
  {
    Pop();
  }
}



template<typename T>
inline void Stack<T>::Push(const T & data)
{
  Node<T>* newNode = new Node<T>();
  newNode->data_ = data;
  newNode->nextNode_ = head_;
  head_ = newNode;
}



template<typename T>
inline bool Stack<T>::IsEmpty() const
{
  return head_ == nullptr ? true : false;
}



template<typename T>
inline std::ostream & Stack<T>::WriteTo(std::ostream & ostrm) const
{
  Node<T>* printed_node(head_);
  ostrm << '{';
  while (printed_node)
  {
    ostrm << printed_node->data_;
    printed_node = printed_node->nextNode_;
    if (printed_node)
    {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const Stack<T>& stack)
{
  return stack.WriteTo(ostrm);
}




template<typename T>
Stack<T>::Stack(const Stack<T>& obj) : Stack<T>()
{
  if (obj.head_ != nullptr)
  {
    head_ = new Node<T>(obj.head_);
    Node<T>* current_this = head_;
    Node<T>* current_copy = obj.head_;
    while (current_copy->nextNode_ != nullptr)
    {
      current_this->nextNode_ = new Node<T>(current_copy->nextNode_);
      current_this = current_this->nextNode_;
      current_copy = current_copy->nextNode_;
    }
  }
};



template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
  if (this != &obj)
  {
    if (head_ == nullptr)
    {
      head_ = new Node<T>();
    }
    head_->data_ = obj.head_->data_;

    Node<T>* current_this = head_;
    Node<T>* current_copy = obj.head_;

    while (current_copy->nextNode_ != nullptr)
    {
      if (current_this->nextNode_ == nullptr)
      {
        current_this->nextNode_ = new Node<T>();
      }
      current_this->nextNode_->nextNode_->data_ = current_copy->nextNode_->data_;
      current_copy = current_copy->nextNode_;
      current_this = current_this->nextNode_;
    }

    Node<T>* tail = current_this->nextNode_;
    current_this->nextNode_ = nullptr;
    while (tail != nullptr)
    {
      Node<T>* p = tail->nextNode_;
      delete tail;
      tail = p;
    }
  }
  return *this;
}



template<typename T>
inline Stack<T>::~Stack()
{
  while (head_ != nullptr)
  {
    Pop();
  }
}
#endif // STACK_2018

