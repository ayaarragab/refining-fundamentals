#include "input_funcs.h"

short count_words(string s) {
  short count = 0;
  for (short i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
      ++count;
  }
  return count + 1;
}

int main() {
    string str = input_funcs::readString("Enter a string");   
    cout << count_words(str);  
    return 0;
}
