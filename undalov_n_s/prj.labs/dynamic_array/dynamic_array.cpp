#include <stdexcept>

#include "dynamic_array.h"

Dynamic_array::Dynamic_array(const int size) 
	: _arr(new double[size])
	, _size(size)
{
	for (int i =0; i < _size; i++)
		_arr[i] = 0;
};

Dynamic_array::~Dynamic_array()
{
	delete[] _arr;
	_arr = nullptr;
	_size = 0;
};

Dynamic_array::Dynamic_array(const Dynamic_array& arr)
	: Dynamic_array(arr._size)
{
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = arr[i];
	}
};

int Dynamic_array::GetSize() const
{
	return _size;
};


double& Dynamic_array::operator[](int index) const
{
	if ((index < 0) || (index > _size)) throw std::invalid_argument("Uncorrect index");
	return _arr[index];
};


