#ifndef Matrix_2018
#define Matrix_2018



class Matrix
{
public:
	explicit Matrix() = default;
	explicit Matrix(const int rows, const int colums);
	explicit Matrix(const Matrix& matr);
	~Matrix();
	double& GetElement(const int row,const int colum) const;
	int GetCountRows() const;
	int GetCountColums() const;

private:

	double** _matrix{nullptr};
	int _sizeRows{0};
	int _sizeColums{0};
};
#endif