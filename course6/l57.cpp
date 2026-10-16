#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void add_vec_content_to_file(string filename, vector<string> &vec, string record="") {
  fstream file;
  file.open(filename, ios::out);
  for (string &str: vec)
  {
    if (record != "" && str != record)
      file << str + "\n";
  }
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

void delete_record(string filename, string record) {
  vector<string> vec;
  read_and_add_to_vec(filename, vec);
  add_vec_content_to_file(filename, vec, record);
}

int main() {
  string filename = "first_file_using_c++.txt", record = "Hello!";
  delete_record(filename, record);
  print_file_content(filename);
  return 0;
}
