#include <bits/stdc++.h>
#include "clsDblLinkedLIst.h"
#include "clsMyQueue.h" // اسم ملف الـ Queue الخاص بك

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsMyQueue<int> MyQueue;

  cout << "=== Testing Push (Enqueue) ==-\n";
  MyQueue.Push(10);
  MyQueue.Push(20);
  MyQueue.Push(30);
  MyQueue.Push(40);

  cout << "Queue Elements: ";
  MyQueue.PrintList();

  cout << "\nQueue Size: " << MyQueue.Size() << "\n";
  cout << "Front Element: " << MyQueue.Front()->val << "\n";
  cout << "Back Element: " << MyQueue.Back()->val << "\n";

  cout << "\n=== Testing Pop (Dequeue) ==-\n";
  MyQueue.Pop();
  cout << "After one Pop():\n";
  cout << "Queue Elements: ";
  MyQueue.PrintList();
  cout << "New Front Element: " << MyQueue.Front()->val << "\n";
  cout << "New Queue Size: " << MyQueue.Size() << "\n";

  cout << "\n=== Testing Empty Queue ==-\n";
  MyQueue.Pop();
  MyQueue.Pop();
  MyQueue.Pop();
  
  MyQueue.PrintList();
  cout << "Is Queue Empty? " << (MyQueue.IsEmpty() ? "Yes" : "No") << "\n";

  return 0;
}