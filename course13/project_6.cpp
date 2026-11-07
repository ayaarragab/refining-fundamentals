#include <bits/stdc++.h>
#include "clsMyStackArr.h"
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsMyStackArr<int> Mystack;

  cout << "=== Testing Push (EnStack) ==-\n";
  Mystack.Push(10);
  Mystack.Push(20);
  Mystack.Push(30);
  Mystack.Push(40);

  cout << "Stack Elements: ";
  Mystack.PrintList();
  cout << "\nStack Size: " << Mystack.Size() << "\n";
  cout << "Top Element: " << Mystack.Top() << "\n";
  cout << "Bottom Element: " << Mystack.Bottom() << "\n";

  cout << "\n=== Testing Pop (DeStack) ==-\n";
  Mystack.Pop();
  cout << "After one Pop():\n";
  cout << "Stack Elements: ";
  Mystack.PrintList();
  cout << "New Top Element: " << Mystack.Top() << "\n";
  cout << "New Stack Size: " << Mystack.Size() << "\n";

  cout << "\n=== Testing Empty Stack ==-\n";
  Mystack.Pop();
  Mystack.Pop();
  Mystack.Pop();
  
  Mystack.PrintList();
  cout << "Is Stack Empty? " << (Mystack.IsEmpty() ? "Yes" : "No") << "\n";

  return 0;
}