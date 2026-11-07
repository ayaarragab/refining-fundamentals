#include <bits/stdc++.h>
#include "clsMyString.h"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clsMyString str;

  str.SetValue("Aya");
  str.SetValue("Ragab");
  str.SetValue("Saleh");

  cout << "Before Undo " << endl;
  cout << str.GetValue() << endl;

  str.Undo();
  
  cout << "After Undo " << endl;
  cout << str.GetValue() << endl;

  str.Undo();
  
  cout << "After Undo For 2nd time" << endl;
  cout << str.GetValue() << endl;

  str.Redo();  
  
  cout << "After Redo " << endl;
  cout << str.GetValue() << endl;

  str.Redo();  
  
  cout << "After Redo For 2nd time" << endl;
  cout << str.GetValue() << endl;
}