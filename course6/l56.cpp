#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void add_vec_content_to_file(string filename, vector<string> &vec) {
  fstream file;
  file.open(filename, ios::out);
  for (string &str: vec)
    file << str + "\n";
  file.close();
}

void print_file_content(string filename) {
  fstream file;
  file.open(filename, ios::in);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
      cout << line << endl;
    file.close();
  }
}

int main() {
  vector<string> strs = { "Aya", "Doaa", "Youssef", "Belal" };
  string filename = "first_file_using_c++.txt";
  add_vec_content_to_file(filename, strs);
  print_file_content(filename);
  return 0;
}
