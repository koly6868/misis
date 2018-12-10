#include <stdexcept>

#include "dynamic_array.h"

Dynamic_array::Dynamic_array(const int size) 

{
  if (size < 0) throw std::invalid_argument("size must be positive");
  size_ = size;
  arr_ = new double[size_];
	for (int i =0; i < size_; i++)
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


