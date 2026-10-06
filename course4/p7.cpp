#include <iostream>
using namespace std;

int readNum() {
  int num;
  cout << "Enter a number \n";
  cin >> num;
  return num;
}

void printNumDiv2(int num) {
  cout << float(num) / 2 << "\n";
}

int main() {
  printNumDiv2(readNum());
  return 0;
}