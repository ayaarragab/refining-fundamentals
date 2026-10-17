#include "input_funcs.h"
#include <vector>

void words_to_vec(string s, vector<string> &str_vec) {
  short from = 0;
  for (short i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
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

int main() {
    vector<string> str_vec;
    string str = input_funcs::readString("Enter a string");   
    words_to_vec(str, str_vec);
    print_vec(str_vec);
    return 0;
}
