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

  cout << "Before Deleting first item: \n";

  MyArray.PrintList();

  MyArray.DeleteFirstItem();
  cout << "After Deleting first item: \n";
  MyArray.PrintList();

  MyArray.DeleteLastItem();
  cout << "After Deleting last item: \n";
  MyArray.PrintList();
  return 0;
}