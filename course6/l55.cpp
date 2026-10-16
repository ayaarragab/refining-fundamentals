#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


void read_and_add_to_vec(string file_name, vector<string> &vec) {
  fstream file;
  file.open(file_name, ios::in);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
      vec.push_back(line);
    cout << "File content is added to the vector!\n";
    file.close();
  }
}

void print_vec_content(vector<string> &vec) {
  vector<string>::iterator iter;
  for (iter = vec.begin(); iter != vec.end(); iter++)
    cout << *iter << endl;
}

int main() {
  vector<string> strs;
  read_and_add_to_vec("first_file_using_c++.txt", strs);
  print_vec_content(strs);
  return 0;
}
