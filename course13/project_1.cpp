#include <bits/stdc++.h>
#include "clsDblLinkedLIst.h"

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsDblLinkedList<int> list = clsDblLinkedList(new Node<int>(2, NULL));

  list.InsertAtBeginning(1);
  cout << "Before adding 3 to the end\n";
  list.PrintList();

  list.InsertAtEnd(3);
  cout << "After adding 3 to the end\n";
  list.PrintList();

  list.InsertAfter(2, 10);
  cout << "After adding 10 after 2\n";
  list.PrintList();

  list.DeleteNode(10);
  cout << "After Deleting 10\n";
  list.PrintList();

  list.DeallocateList();

  return 0;
}
