#pragma once
#include "clsMyStack.h"

class clsMyString
{
private:
  clsMyStack<string> _values_stack;
  clsMyStack<string> _redo_stack;
public:
  void SetValue(string str) {
    _values_stack.Push(str);
  }
  string GetValue() {
    return (_values_stack.Top())->val;
  }
  void Undo() {
    if (!_values_stack.IsEmpty())
    {
    _redo_stack.Push((_values_stack.Top())->val);
    _values_stack.Pop();    
    }
    
  }
  void Redo() {
    if (!_redo_stack.IsEmpty())
    {
    _values_stack.Push((_redo_stack.Top())->val);
    _redo_stack.Pop();    
  }
    
  }
};