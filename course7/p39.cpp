#include "input_funcs.h"
#include <vector>

string join(vector<string> &vec, char delim) {
  string str = "";
  for (string &s : vec)
  {
    str.append(s);
    str.append(1, delim);
  }
  
  return str.substr(0, str.length() - 1); 
}


int main() {
    vector<string> vec = { "Aya", "Doaa", "Youssef", "Belal" };
    cout << join(vec, ',') << endl; 
    return 0;
}
