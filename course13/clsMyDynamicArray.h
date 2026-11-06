#pragma once
#include "clsDblLinkedLIst.h"

template <typename T>
class clsMyDynamicArray
{
protected:
  clsDblLinkedList<T> _list;
  int _length;
public:
  clsMyDynamicArray(int length) {
    _length = length;
    while (length--)
      _list.InsertAtEnd(0);
  }
  void SetItem(int idx, int val) {
    _list.InsertAfter(idx - 1, val);
  }
  void PrintList() {
    _list.PrintList();
  }
  bool IsEmpty() {
    return _list.IsEmpty();
  }
};