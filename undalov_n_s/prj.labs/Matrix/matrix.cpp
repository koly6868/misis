#include <stdexcept>

#include "matrix.h"

Matrix::~Matrix()
{
	for (int i = 0; i < _sizeRows; i++)
	{
		delete [] _matrix[i];
	}
	delete [] _matrix;
}

Matrix::Matrix(const int rows, const int colums) 
	: _matrix(new double*[rows])
	, _sizeRows(rows)
	, _sizeColums(colums)
{
	for (int i = 0; i < _sizeRows; i++)
	{
		_matrix[i] = new double[_sizeColums];

		for (int j = 0; j < _sizeColums; j++)
		{
			_matrix[i][j] = 0;
		}
		
	}
};

Matrix::Matrix(const Matrix& matr)
	: Matrix(matr._sizeRows, matr._sizeColums)
{
	for (int i = 0; i < _sizeRows; i++)
	{
		for (int j = 0; j < _sizeColums; j++)
		{
			_matrix[i][j] = matr._matrix[i][j];
		}
	}
};

double& Matrix::GetElement(const int row, const int colum) const
{
	if ((row < 0) || (row >= _sizeRows) || (colum < 0) || (colum >= _sizeColums)) throw std::invalid_argument("Uncorrect index");
	return _matrix[row][colum]; 
};

int Matrix::GetCountRows() const
{
	return _sizeRows;
};

int Matrix::GetCountColums() const
{
	return _sizeColums;
};

