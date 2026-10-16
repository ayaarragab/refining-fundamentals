#include <fstream>
#include <iostream>
using namespace std;

int main() {
  fstream file;
  file.open("first_file_using_c++.txt", ios::in);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
      cout << line << endl;
    file.close();
  }
  return 0;
}
