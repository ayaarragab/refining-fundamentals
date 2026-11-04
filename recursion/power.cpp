#include <iostream>

using namespace std;


int power(int a, int b) {
  if (b == 1)
    return a;
  return a * power(a, b - 1);
}

int main() {
  cout << power(3, 2) << endl;
  return 0;
}