#include "input_funcs.h"
#include <vector>

void words_to_vec(string s, vector<string> &str_vec, char delim) {
  short from = 0;
  for (short i = 0; i < s.length(); i++)
  {
    if (s[i] == delim)
    {
      str_vec.push_back(s.substr(from, i));
      from = i + 1;
    }
  }
  str_vec.push_back(s.substr(from, s.length()));
}

void print_vec(vector<string> &str_vec) {
  for (string &s : str_vec)
   cout << s << endl;  
}

string replace_word(string s, char delim, string word, string new_word) {
  vector<string> str_vec;
  words_to_vec(s, str_vec, delim);
  string new_str = "";

  for (string s : str_vec)
  {
    if (s != word)
      new_str.append(s);
    else
      new_str.append(new_word);
    new_str.append(1, delim);
  }
  

  return new_str.substr(0, new_str.length() - 1);
}

int main() {
    string str = input_funcs::readString("Enter a string");  
    cout << replace_word(str, ' ', "Ragab", "Mostafa") << endl; 
    return 0;
}
