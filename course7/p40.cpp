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

string join(string arr[], short size, char delim) {
  string str = "";
  for (short i = 0; i < size; i++)
  {
    str.append(arr[i]);
    str.append(1, delim);
  }
  
  return str.substr(0, str.length() - 1);  
}

int main() {
    string arr[] = { "Aya", "Doaa", "Youssef", "Belal" };
    cout << join(arr, 4, ',') << endl; 
    return 0;
}
