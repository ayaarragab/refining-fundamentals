#pragma once
#include "clsDblLinkedLIst.h"

template <typename T> class clsMyQueue: public clsDblLinkedList<T>
{
private:
  /* data */
public:
  void Push(T val) {
    this->InsertAtEnd(val);
  }
  void Pop() {
    this->DeleteFirstNode();
  }
  Node<T>* Front() {
    return this->head;
  }
  Node<T>* Back() {
    return this->tail;
  }
};