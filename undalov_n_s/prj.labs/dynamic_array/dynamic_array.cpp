#include <stdexcept>
#include "dynamic_array.h"



Dynamic_array::Dynamic_array(const int size)
{
  if (size < 0) throw std::invalid_argument("size must be positive");
  size_ = size;
  arr_ = new double[size_];
  for (int i = 0; i < size_; i++)
    arr_[i] = 0;
};



Dynamic_array::~Dynamic_array()
{
  delete[] arr_;
  arr_ = nullptr;
  size_ = 0;
};



Dynamic_array::Dynamic_array(const Dynamic_array& arr)
  : Dynamic_array(arr.size_)
{
  for (int i = 0; i < size_; i++)
  {
    arr_[i] = arr[i];
  }
};



int Dynamic_array::GetSize() const
{
  return size_;
};




double& Dynamic_array::operator[](int index) const
{
  if ((index < 0) || (index >= size_)) throw std::invalid_argument("Uncorrect index");
  return arr_[index];
};



Dynamic_array& Dynamic_array::operator=(const Dynamic_array& arr)
{
  if (&arr != this)
  {
    if (arr.size_ > size_)
    {
      double* newArr = new double[arr.size_];
      delete[] arr_;
      arr_ = newArr;
    }
    size_ = arr.size_;
    for (int i = 0; i < size_; i++)
    {
      arr_[i] = arr[i];
    }
  }
  return *this;
};



void Dynamic_array::Resize(const int size)
{
  if (size < 0) throw std::invalid_argument("Invalid argument");

  double* arr = new double[size];
  if (size <= size_)
  {
    for (int i = 0; i < size; i++)
    {
      arr[i] = arr_[i];
    }
  }
  else
  {
    for (int i = 0; i < size_; i++)
    {
      arr[i] = arr_[i];
    }
  }
  delete [] arr_;
  arr_ = arr;
  size_ = size;
}


