#include "input_funcs.h"
#include <vector>

string replace_word(string s, string word, string new_word) {
  int pos = s.find(word);
  while (pos != string::npos)
  {
    s = s.replace(pos, word.length(), new_word);
    pos = s.find(word);
  }

  return s;
}

int main() {
    string str = input_funcs::readString("Enter a string");  
    cout << replace_word(str, "Ragab", "") << endl; 
    return 0;
}
