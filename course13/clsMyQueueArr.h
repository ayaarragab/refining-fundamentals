#pragma once
#include "clsMyDynamicArray.h"

template <typename T> class clsMyQueueArr
{
protected:
  clsMyDynamicArray<T> _list;
public:
  void Push(T val) {
    _list.InsertAtEnd(val);
  }
  void Pop() {
    _list.DeleteLastItem();
  }
  T Front() {
    return _list.GetItem(0);
  }
  T Back() {
    return _list.GetItem(_list.Size() - 1);
  }

  void PrintList() {
    _list.PrintList();
  }

  int Size() {
    return _list.Size();
  }

  bool IsEmpty() {
    return _list.IsEmpty();
  }

  T GetItem(int idx) {
    return _list.GetItem(idx);
  }

  bool UpdateItem(int idx, T val) {
    return _list.SetItem(idx, val);
  }

  void InsertAfter(int idx, int val) {
    return _list.InsertAfter(idx, val);
  }

  void InsertAtFront(int val) {
    return _list.InsertAtBeginning(val);
  }

  void InsertAtBack(int val) {
    return _list.InsertAtEnd(val);
  }

  void Reverse() {
    _list.Reverse();
  }

  void Clear() {
    _list.Clear();
  }
};