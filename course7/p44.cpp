#include "input_funcs.h"
#include <cctype>


string remove_punct(string &s) {
  string new_s = "";
  for (short i = 0; i < s.length(); i++)
  {
    if (ispunct(s[i]))
      continue;
    new_s.append(1, s[i]);
  }
  return new_s;
}

int main() {
    string str = input_funcs::readString("Enter a string");  
    cout << "Without puncs is " << remove_punct(str) << endl;
    return 0;
}
