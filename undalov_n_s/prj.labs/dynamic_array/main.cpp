#include <iostream>

#include "dynamic_array.h"

bool Test_Dynamic_array();

int main()
{
	Test_Dynamic_array();
	return 0;
}

bool Test_Dynamic_array()
{
	using namespace std;
	Dynamic_array arr1;
	Dynamic_array arr2(3);
	Dynamic_array arr3(arr2);


	cout << "use constructors" << endl;
	// empty constr
	cout << "arr1 size: " << arr1.GetSize() << " elements: ";
	for (int i = 0; i < arr1.GetSize(); i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	//constr trough size
	cout << "arr2 size: " << arr2.GetSize() << " elements: ";
	for (int i = 0; i < arr2.GetSize(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	//copy constr
	cout << "arr3 size: " << arr3.GetSize() << " elements: ";
	for (int i = 0; i < arr2.GetSize(); i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl;

	arr2[0] = 5;
	Dynamic_array arr4(arr2);
	cout << "change first element on 5 and after that copy arr2 to arr4" << endl << endl;
	cout << "arr2 size: " << arr2.GetSize() << " elements: ";
	for (int i = 0; i < arr2.GetSize(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	cout << "arr3 size: " << arr4.GetSize() << " elements: ";
	for (int i = 0; i < arr4.GetSize(); i++)
	{
		cout << arr4[i] << " ";
	}
	cout << endl;

	return true;
}



