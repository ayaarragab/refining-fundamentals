#pragma once
#include "clsDblLinkedLIst.h"

template <typename T> class clsMyQueue
{
protected:
  clsDblLinkedList<T> _list;
public:
  void Push(T val) {
    _list.InsertAtEnd(val);
  }
  void Pop() {
    _list.DeleteFirstNode();
  }
  Node<T>* Front() {
    return _list.head;
  }
  Node<T>* Back() {
    return _list.tail;
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
    return _list.UpdateItem(idx, val);
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