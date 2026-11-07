#include <bits/stdc++.h>
#include "clsDblLinkedLIst.h"
#include "clsMyQueueArr.h"
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsMyQueueArr<int> myQueue;

  cout << "=== Testing Push (Enqueue) ==-\n";
  myQueue.Push(10);
  myQueue.Push(20);
  myQueue.Push(30);
  myQueue.Push(40);

  cout << "Queue Elements: ";
  myQueue.PrintList();

  cout << "\nQueue Size: " << myQueue.Size() << "\n";
  cout << "Front Element: " << myQueue.Front() << "\n";
  cout << "Back Element: " << myQueue.Back() << "\n";

  cout << "\n=== Testing Pop (Dequeue) ==-\n";
  myQueue.Pop();
  cout << "After one Pop():\n";
  cout << "Queue Elements: ";
  myQueue.PrintList();
  cout << "New Front Element: " << myQueue.Front() << "\n";
  cout << "New Queue Size: " << myQueue.Size() << "\n";

  cout << "\n=== Testing Empty Queue ==-\n";
  myQueue.Pop();
  myQueue.Pop();
  myQueue.Pop();
  
  myQueue.PrintList();
  cout << "Is Queue Empty? " << (myQueue.IsEmpty() ? "Yes" : "No") << "\n";

  return 0;
}