#pragma once
#include "clsDblLinkedLIst.h"

template <typename T> class clsMyQueue
{
protected:
  clsDblLinkedList<T> _list;
public:
  void Push(T val) {
    _list->InsertAtEnd(val);
  }
  void Pop() {
    _list->DeleteFirstNode();
  }
  Node<T>* Front() {
    return _list->head;
  }
  Node<T>* Back() {
    return _list->tail;
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
};