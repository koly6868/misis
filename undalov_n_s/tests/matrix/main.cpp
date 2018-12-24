#include <iostream>
#include <stdexcept>

#include "../../prj.labs/matrix/matrix.h"

bool MatrixTest();
void WriteMatrix(Matrix& matr);

int main()
{
	MatrixTest();
	return 0;
};

bool MatrixTest()
{
	using namespace std;
	Matrix matr1;
	Matrix matr2(2,2);
	Matrix matr3(matr2);
	
	cout << "use constructors" << endl;
	cout << "empty constr:" << endl;
	cout << "arr1 sizes: [" << matr1.GetCountRows() << "," << matr1.GetCountColums() << "] elements: " << endl;
	WriteMatrix(matr1);
	cout << endl;
	cout << "constr trough sizes:" << endl;
	cout << "arr2 sizes: [" << matr2.GetCountRows() << "," << matr2.GetCountColums() << "] elements: " << endl;
	WriteMatrix(matr2);
	cout << endl;

	cout << "copy constructor:" << endl;
	cout << "arr3 sizes: [" << matr3.GetCountRows() << "," << matr3.GetCountColums() << "] elements: " << endl;
	WriteMatrix(matr3);

	cout << endl;

	cout << "write value to matrix" << endl;
	matr3.At(1,1) = 10;

	cout << "arr3 sizes: [" << matr3.GetCountRows() << "," << matr3.GetCountColums() << "] elements: " << endl;
	WriteMatrix(matr3);
	cout << endl;

	cout << "get elemet [1,1] by last matrix" << endl;
	cout << matr3.At(1,1) << endl;
	
	cout << "uncorrect([2,2]) get element by last matrix" << endl;
	double el(0);
	try
	{
		el =matr3.At(2,2);
		cout << el << endl;
	}
	catch(exception e){
		cout << e.what();
	}
	cout << endl;

  Matrix m(2,2);
  Matrix l(2,2);
  m.At(0,0) = 1;
  m.At(0, 1) = 2;
  m.At(1, 0) = 3;
  m.At(1, 1) = 4;
  l.At(0,0) = 5;
  l.At(1,0) = 6;
  l.At(1,0) = 4;
  l.At(1,1) = 6;
  cout << "first matrix" << endl;
	WriteMatrix(m);
  cout << "second matrix" << endl;
  WriteMatrix(l);
  
  cout << "GetCountRows by second matrix" << endl;
  cout << m.GetCountRows() << endl;

  cout << "GetCountColums by second matrix" << endl;
  cout << m.GetCountColums() << endl;

  cout << "first + second" << endl;
  WriteMatrix(m + l);
  cout << "first - second" << endl;
  WriteMatrix(m - l);
  cout << "first = second" << endl;
  m = l;
  WriteMatrix(m);

  return true;
}

void WriteMatrix(Matrix& matr)
{
using namespace std;
	for (int i = 0; i < matr.GetCountRows(); i++)
	{
		for (int j = 0; j < matr.GetCountColums(); j++)
		{
			cout << matr.At(i, j) << " ";
		}
		cout << endl;
	}
}

