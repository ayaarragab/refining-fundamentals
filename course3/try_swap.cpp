#include <iostream>
using namespace std;


void func(int &x, int &y) {
  int temp;
  temp = y;
  y = x;
  x = temp;
}

int main() {
  int x = 10, y = 5;

  func(x, y);
  cout << "x and y are " << x << " " << y << "\n";
  return 0;
}