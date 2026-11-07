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

  cout << "Before Reversing : \n";
  MyArray.PrintList();
  
  MyArray.Reverse();
  cout << "After Reversing : \n";
  MyArray.PrintList();

  cout << MyArray.GetItem(2) << endl;
  MyArray.Clear();
  MyArray.PrintList();
  return 0;
}