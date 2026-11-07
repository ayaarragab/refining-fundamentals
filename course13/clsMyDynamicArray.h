#include <bits/stdc++.h>
#pragma once

using namespace std;

template <typename T>
class clsMyDynamicArray
{
private:
  bool _IsIdxValid(int idx)
  {
    return ((idx < _length) && (idx >= 0));
  }

protected:
  T *_Array;
  int _length;

public:
  clsMyDynamicArray(int length)
  {
    if (length > 0)
    {
      _length = length;
      _Array = new T[length];
    }
    else
      _length = 0;
  }
  ~clsMyDynamicArray()
  {
    delete[] _Array;
  }
  void SetItem(int idx, int val)
  {
    if (!_IsIdxValid(idx))
      return;

    _Array[idx] = val;
  }
  void PrintList()
  {
    cout << endl;
    for (short i = 0; i < _length; i++)
      cout << _Array[i] << endl;
    cout << "\n\n";
  }
  bool IsEmpty()
  {
    return !_length;
  }
  void Resize(int newSize) {
    T* new_arr = new T[newSize];
    for (short i = 0; i < newSize; i++) {
      if (i < _length)
        new_arr[i] = _Array[i];
      else
        break;
    }
    _Array = new_arr;
    _length = newSize;
  }
};