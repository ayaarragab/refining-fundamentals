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

  void _Reverse(int l, int r)
  {
    if (l == r || l > r)
      return;
    T temp = _Array[l];
    _Array[l] = _Array[r];
    _Array[r] = temp;
    _Reverse(l + 1, r - 1);
  }

  void _SwapEntries(T &e1, T &e2)
  {
    T temp = e1;
    e1 = e2;
    e2 = temp;
  }

  void _Shift(int idx)
  {
    if (!_IsIdxValid(idx))
      return;
    if (idx == _length - 1)
      return;
    _SwapEntries(_Array[idx], _Array[idx + 1]);
    _Shift(idx + 1);
  }

protected:
  T *_Array;
  int _length;

public:
  clsMyDynamicArray(int length = 0)
  {
    if (length > 0)
    {
      _length = length;
      _Array = new T[length];
    }
    else
    {
      _length = 0;
      _Array = nullptr;
    }
  }

  ~clsMyDynamicArray()
  {
    if (!_IsCleared)
      Clear();
  }

  int Size() {
    return _length;
  }

  void SetItem(int idx, T val)
  {
    if (!_IsIdxValid(idx))
      return;

    _Array[idx] = val;
  }

  void PrintList()
  {
    cout << endl;
    for (short i = 0; i < _length; i++)
      cout << "Index[" << i << "]: " << _Array[i] << endl;
    cout << "\n\n";
  }

  bool IsEmpty()
  {
    return !_length;
  }

  void Resize(int newSize)
  {
    if (newSize < 0)
      newSize = 0;

    T *new_arr = new T[newSize];
    for (short i = 0; i < newSize; i++)
    {
      if (i < _length)
        new_arr[i] = _Array[i];
      else
        break;
    }
    delete[] _Array;
    _Array = new_arr;
    _length = newSize;
  }

  void Clear()
  {
    delete[] _Array;
    _Array = nullptr;
    _length = 0;
    _IsCleared = true;
  }

  void Reverse()
  {
    if (_length > 0)
      _Reverse(0, _length - 1);
  }

  T GetItem(int idx)
  {
    return _Array[idx];
  }

  void DeleteItemAt(int idx)
  {
    if (!_IsIdxValid(idx))
      return;
    _Shift(idx);
    --_length;
  }

  void DeleteFirstItem()
  {
    DeleteItemAt(0);
  }

  void DeleteLastItem()
  {
    if (_length > 0)
      DeleteItemAt(_length - 1);
  }

  int Find(T value)
  {
    int i = 0;
    T val;
    while (i < _length)
    {
      val = GetItem(i);
      if (val == value)
        return i;
      ++i;
    }
    return -1;
  }

  int DeleteItem(T item)
  {
    int idx = Find(item);
    if (idx != -1)
      DeleteItemAt(idx);
    return idx;
  }

  void InsertAt(int idx, T val)
  {
    if (idx < 0 || idx > _length)
      return;
    
    T *newArr = new T[_length + 1];

    for (int i = 0; i < idx; ++i)
      newArr[i] = _Array[i];

    newArr[idx] = val;

    for (int i = idx; i < _length; ++i)
      newArr[i + 1] = _Array[i];

    delete[] _Array;
    _Array = newArr;
    ++_length;
  }

  void InsertAtBeginning(T val) {
    InsertAt(0, val);
  }

  void InsertBefore(int idx, T val) {
    if (idx < 0 || idx > _length)
      return;
    InsertAt(idx, val);
  }

  void InsertAfter(int idx, T val) {
    if (idx < 0 || idx > _length)
      return;
    InsertAt(idx + 1, val);
  }

  void InsertAtEnd(T val) {
    InsertAt(_length, val);
  }
};