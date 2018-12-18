#ifndef MATRIX_2018
#define MATRIX_2018

#include <stdexcept>
#include "matrix.h"

Matrix::~Matrix()
{
  for (int i = 0; i < count_rows_; i++)
  {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}



Matrix::Matrix(const int rows, const int colums)
{
  if ((rows < 0) || (colums < 0)) throw std::invalid_argument("rows or colums less than 0");

  matrix_ = new double*[rows];
  count_rows_ = rows;
  count_colums_ = colums;

  for (int i = 0; i < count_rows_; i++)
  {
    matrix_[i] = new double[count_colums_];
    for (int j = 0; j < count_colums_; j++)
    {
      matrix_[i][j] = 0;
    }
  }
};



Matrix::Matrix(const Matrix& matr)
  : Matrix(matr.count_rows_, matr.count_colums_)
{
  for (int i = 0; i < count_rows_; i++)
  {
    for (int j = 0; j < count_colums_; j++)
    {
      matrix_[i][j] = matr.matrix_[i][j];
    }
  }
};



const double Matrix::At(const int row, const int colum) const
{
  if ((row < 0) || (row >= count_rows_) || (colum < 0) || (colum >= count_colums_))
    throw std::invalid_argument("Uncorrect index");
  return matrix_[row][colum];
};



double& Matrix::At(const int row, const int colum)
{
  if ((row < 0) || (row >= count_rows_) || (colum < 0) || (colum >= count_colums_))
    throw std::invalid_argument("Uncorrect index");
  return matrix_[row][colum];
}



Matrix& Matrix::operator+=(const Matrix& matr)
{
  if ((count_colums_ != matr.count_colums_) || (count_rows_ != matr.count_rows_))
    throw std::logic_error("sum error");

  for (int i = 0; i < count_rows_; i++)
  {
    for (int j = 0; j < count_colums_; j++)
    {
      matrix_[i][j] += matr.At(i, j);
    }
  }
  return *this;
}



Matrix& Matrix::operator-=(const Matrix& matr)
{
  if ((count_colums_ != matr.count_colums_) || (count_rows_ != matr.count_rows_))
    throw std::logic_error("sum error");

  for (int i = 0; i < count_rows_; i++)
  {
    for (int j = 0; j < count_colums_; j++)
    {
      matrix_[i][j] -= matr.At(i, j);
    }
  }
  return *this;
}



Matrix& Matrix::operator=(const Matrix& matr)
{
  if (&matr != this)
  {
    if ((matr.count_colums_ > count_colums_) || (matr.count_rows_ > count_rows_))
    {
      double ** new_matr = new double *[matr.count_rows_];
      for (int i = 0; i < matr.count_rows_; i++)
      {
        new_matr[i] = new double[matr.count_colums_];
      }
      for (int i = 0; i < count_rows_; i++)
      {
        delete[] matrix_[i];
      }
      delete[] matrix_;
      matrix_ = new_matr;
    }
    count_colums_ = matr.count_colums_;
    count_rows_ = matr.count_rows_;
    for (int i = 0; i < count_rows_; i++)
    {
      for (int j = 0; j < count_colums_; j++)
      {
        matrix_[i][j] = matr.matrix_[i][j];
      }
    }
  }
  return *this;
}


int Matrix::GetCountRows() const
{
  return count_rows_;
};



int Matrix::GetCountColums() const
{
  return count_colums_;
};



Matrix operator+(const Matrix& matr1, const Matrix& matr2)
{
  return (Matrix(matr1) += matr2);
};



Matrix operator-(const Matrix& matr1, const Matrix& matr2)
{
  return (Matrix(matr1) -= matr2);
};
#endif // MATRIX_2018

