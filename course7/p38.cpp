#include "input_funcs.h"

void print_words(string s) {
  short from = 0;
  for (short i = 0; i < s.length(); i++)
  {
    if (s[i+1] == ' ')
    {
      cout << s.substr(from, i+1) << endl;
      from = i+2;
    }
  }
  cout << s.substr(from, s.length()) << endl;
}

int main() {
    string str = input_funcs::readString("Enter a string");   
    print_words(str);  
    return 0;
}
