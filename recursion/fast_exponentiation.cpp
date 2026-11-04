#include <iostream>

using namespace std;


int power(int a, int b) {
  if (b == 0)
    return 1;
  int half_res = power(a, b/2);
  int res = half_res * half_res;
  return ((b & 1) ? res * a: res);
}

int main() {
  cout << power(3, 3) << endl;
  return 0;
}