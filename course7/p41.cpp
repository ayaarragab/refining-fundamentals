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
  int last = str_vec.size();
  for (int i = last; i >= 0; i--)
  {
    new_str.append(str_vec[i]);
    if (i != 0)
      new_str.append(1, delim);
  }
  return new_str;
}

int main() {
    string str = input_funcs::readString("Enter a string");  
    cout << "Reveresed string is " << reverse_string(str, ' ') << endl; 
    return 0;
}
