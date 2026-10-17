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

string reverse_string(string s, char delim) {
  vector<string> str_vec;
  words_to_vec(s, str_vec, delim);
  string new_str = "";
  vector<string>::iterator iter_ = str_vec.end();
  while (iter_ != str_vec.begin())
  {
    new_str.append(*(iter_));
    new_str.append(1, delim);
    iter_--;
  }
  new_str.append(*(iter_));
  return new_str;
}

int main() {
    string str = input_funcs::readString("Enter a string");  
    cout << "Reveresed string is " << reverse_string(str, ' ') << endl; 
    return 0;
}
