#include <iostream>
using namespace std;


int readNum() {
  int num;
  cout << "Enter a number \n";
  cin >> num;
  return num;
}

int max_(int num1, int num2) {
  if (num1 > num2)
    return num1;
  return num2;
}

int main() {
  int num1, num2;
  num1 = readNum();
  num2 = readNum();
  cout << max_(num1, num2) << "\n";
}