#pragma once
#include "clsMyQueue.h"
#include "clsDblLinkedLIst.h"
template <typename T> class clsMyStack: public clsMyQueue<T>
{
  public:
    void Push(T val) {
      clsMyQueue<T>::_list.InsertAtBeginning(val);
    }
    Node<T> * Top() {
      return this->Front();
    }
    Node<T> * Bottom() {
      return this->Back();
    }
};