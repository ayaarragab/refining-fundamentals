#pragma once
#include "clsMyQueueArr.h"
#include "clsDblLinkedLIst.h"
template <typename T> class clsMyStackArr: public clsMyQueueArr<T>
{
  public:
    void Push(T val) {
      clsMyQueueArr<T>::_list.InsertAtBeginning(val);
    }
    T Top() {
      return this->Front();
    }
    T Bottom() {
      return this->Back();
    }
};