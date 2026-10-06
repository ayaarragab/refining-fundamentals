#include <iostream>
using namespace std;

void printName (string name) {
  cout << name + "\n";
}

void readName (string &name) {
  getline(cin, name);
}

int main() {
  string name;
  readName(name);
  printName(name);
  return 0;
}