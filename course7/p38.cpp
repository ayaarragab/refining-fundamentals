#include "input_funcs.h"

string trim_left(string str) {
  short i;
  for (i = (str.length() - 1); i > 0; i--)
  {
    if (str[i] == ' ')
      continue;
    else
      break;
  }
  return str.substr(0, i + 1); 
}

string trim_right(string str) {
  short i;
  for (i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ')
      continue;
    else
      break;
  }
  return str.substr(i, str.length()); 
}

string my_trim(string s) {
  s = trim_left(s);
  s = trim_right(s);
  return s;
}

int main() {
    string str = input_funcs::readString("Enter a string");  
    cout << "(" << my_trim(str)  << ")" << endl; 
    return 0;
}
