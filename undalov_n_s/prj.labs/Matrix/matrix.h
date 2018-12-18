#ifndef MY_MATRIX_2018
#define MY_MATRIX_2018

class Matrix
{
public:
	explicit Matrix() = default;
	explicit Matrix(const int rows, const int colums);
	Matrix(const Matrix& matr);
	~Matrix();
  Matrix& operator+=(const Matrix& matr);
  Matrix& operator-=(const Matrix& matr);
  Matrix& operator=(const Matrix& matr);
	double& At(const int row,const int colum);
  const double At(const int row, const int colum) const;
	int GetCountRows() const;
	int GetCountColums() const;

private:
	double** matrix_{nullptr};
	int count_rows_{0};
	int count_colums_{0};
};


Matrix operator+(const Matrix& matr1, const Matrix& matr2);
Matrix operator-(const Matrix& matr1, const Matrix& matr2);
#endif //MY_MATRIX_2018