#include <iostream>

#include "matrix.h"

bool MatrixTest();

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
	// empty constr
	cout << "arr1 sizes: [" << matr1.GetCountRows() << "," << matr1.GetCountColums() << "] elements: " << endl;
	for (int i = 0; i < matr1.GetCountRows(); i++)
	{
		for (int j = 0; j < matr1.GetCountColums(); i++)
		{
		cout << matr1.GetElement(i,j)  << " ";
		}
		cout << endl;
	}
	cout << endl;

	//constr trough sizes
	cout << "arr2 sizes: [" << matr2.GetCountRows() << "," << matr2.GetCountColums() << "] elements: " << endl;
	for (int i = 0; i < matr2.GetCountRows(); i++)
	{
		for (int j = 0; j < matr2.GetCountColums(); j++)
		{	
			cout << matr2.GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	//copy constructor
	cout << "arr3 sizes: [" << matr3.GetCountRows() << "," << matr3.GetCountColums() << "] elements: " << endl;
	for (int i = 0; i < matr3.GetCountRows(); i++)
	{
		for (int j = 0; j < matr3.GetCountColums(); j++)
		{
			cout << matr3.GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	//write value to matrix
	matr3.GetElement(1,1) = 10;
	Matrix matr4(matr3);

	cout << "arr3 sizes: [" << matr3.GetCountRows() << "," << matr3.GetCountColums() << "] elements: " << endl;
	for (int i = 0; i < matr3.GetCountRows(); i++)
	{
		for (int j = 0; j < matr3.GetCountColums(); j++)
		{
			cout << matr3.GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "arr4 sizes: [" << matr4.GetCountRows() << "," << matr4.GetCountColums() << "] elements: " << endl;
		for (int i = 0; i < matr4.GetCountRows(); i++)
		{
			for (int j = 0; j < matr4.GetCountColums(); j++)
			{
				cout << matr4.GetElement(i, j) << " ";
			}
			cout << endl;
		}
	cout << endl;

	return true;
}