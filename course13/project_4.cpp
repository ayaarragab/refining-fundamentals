#include <bits/stdc++.h>
#include "clsMyDynamicArray.h"
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsMyDynamicArray<int> MyArray(4);

  cout << "=== Testing Push (EnArray) ==-\n";
  MyArray.SetItem(0, 10);
  MyArray.SetItem(1, 20);
  MyArray.SetItem(2, 30);
  MyArray.SetItem(3, 40);

  cout << "Array Elements Before Resizingto 2: ";
  MyArray.PrintList();
  
  cout << "Array Elements After Resizing to 2: ";
  MyArray.Resize(2);
  MyArray.PrintList();
  
  cout << "Array Elements After Resizing to 10: ";
  MyArray.Resize(10);
  MyArray.PrintList();

  return 0;
}