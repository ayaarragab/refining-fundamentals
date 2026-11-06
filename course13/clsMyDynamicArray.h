#include <bits/stdc++.h>
#pragma once

using namespace std;

template <typename T>
class clsMyDynamicArray
{
private:
  bool _IsIdxValid(int idx) {
    return ((idx < _length) && (idx >= 0));
  }
protected:
  T* _Array;
  int _length;
public:
  clsMyDynamicArray(int length) {
    _length = length;
    _Array = new T[length];
  }
  void SetItem(int idx, int val) {
    if (!_IsIdxValid(idx))
      return;
    
    _Array[idx] = val;
  }
  void PrintList() {
    for (short i = 0; i < _length; i++)
      cout << _Array[i] << endl;
    
  }
  bool IsEmpty() {
    return !_length;
  }
};