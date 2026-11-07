#include <bits/stdc++.h>
#include "clsMyDynamicArray.h"
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsMyDynamicArray<int> MyArray(5);

  cout << "=== Testing Push (EnArray) ==-\n";
  MyArray.SetItem(0, 10);
  MyArray.SetItem(1, 20);
  MyArray.SetItem(2, 30);
  MyArray.SetItem(3, 40);
  MyArray.SetItem(4, 100);

  cout << "Before inserting Element 50 at index 2: \n";

  MyArray.PrintList();

  MyArray.InsertAt(2, 50);
  cout << "After inserting Element 50 at index 2" << endl;
  MyArray.PrintList();
  return 0;
}