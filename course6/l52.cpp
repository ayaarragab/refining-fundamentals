#include <fstream>
#include <iostream>
using namespace std;

int main() {
  fstream file;
  file.open("first_file_using_c++.txt", ios::out);
  if (file.is_open())
  {
    file << "Hello!\n";
    file << "It's me!\n";
    file << "Hello!\n";
    file << "Can you hear me!\n";
  }
  return 0;
}
