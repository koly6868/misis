#include <iostream>
#include "../../prj.labs/dynamic_array/dynamic_array.h"

bool Test_Dynamic_array();
void WriteArray(Dynamic_array& arr);

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


  cout << "TEST CONSTRUCTORS" << endl;
  cout << "Dynamic_array()" << endl;
  cout << "arr1 size: " << arr1.GetSize() << " elements: ";
  WriteArray(arr1);
  cout << endl;

  cout << "Dynamic_array(3)" << endl;
  cout << "arr2 size: " << arr2.GetSize() << " elements: ";
  WriteArray(arr2);
  cout << endl;

  cout << "Dynamic_array(Dynamic_array)" << endl;
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

  cout << "call GetSize() by arr3" << endl;
  cout << arr3.GetSize() << endl;

  cout << "test \'=\' " << endl;
  Dynamic_array asd;
  asd = Dynamic_array(2);
  WriteArray(asd);
  cout << endl;

  cout << "call asd.resize(1)" << endl;
  asd.Resize(1);
  WriteArray(asd);
  return true;
}

void WriteArray(Dynamic_array& arr)
{
  using namespace std;
  for (int i = 0; i < arr.GetSize(); i++)
  {
    cout << arr[i] << " ";
  }
}



