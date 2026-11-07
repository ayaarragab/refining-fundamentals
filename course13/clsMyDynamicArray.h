#include <bits/stdc++.h>
#pragma once

using namespace std;

template <typename T>
class clsMyDynamicArray
{
private:
  bool _IsCleared = false;
  bool _IsIdxValid(int idx)
  {
    return ((idx < _length) && (idx >= 0));
  }
  void _Reverse(int l, int r) {
    if (l == r || l > r)
      return;
    T temp = _Array[l];
    _Array[l] = _Array[r];
    _Array[r] = temp;
    _Reverse(l + 1, r - 1);
  }
  void _SwapEntries(T &e1, T &e2) {
    T temp = e1;
    e1 = e2;
    e2 = temp;
  }
  void _DeleteAtItem(int idx) {
    if(!_IsIdxValid(idx))
      return;
    if (idx == _length - 1)
      return;
    _SwapEntries(_Array[idx], _Array[idx + 1]);
    _DeleteAtItem(idx + 1);
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
    if (!_IsCleared)
      Clear();
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
      cout << "Index["  << i << "]: " << _Array[i] << endl;
    cout << "\n\n";
  }

  bool IsEmpty()
  {
    return !_length;
  }

  void Resize(int newSize) {
    if (newSize < 0)
      newSize = 0;
    
    T* new_arr = new T[newSize];
    for (short i = 0; i < newSize; i++) {
      if (i < _length)
        new_arr[i] = _Array[i];
      else
        break;
    }
    delete[] _Array;
    _Array = new_arr;
    _length = newSize;
  }

  void Clear() {
    delete[] _Array;
    _length = 0;
    _IsCleared = true;
  }

  void Reverse() {
    _Reverse(0, _length - 1);
  }

  T GetItem(int idx) {
    return _Array[idx];
  }

  void DeleteItemAt(int idx) {
    _DeleteAtItem(idx);
    --_length;
  }
};