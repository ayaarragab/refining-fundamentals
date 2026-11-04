#include <iostream>

using namespace std;


int power(int a, int b) {
  if (b == 0)
    return 1;
  if ((b & 1) == 0) {
    int half_res = power(a, b/2);
    return half_res * half_res;
  } else {
    int half_res = power(a, b/2);
    return half_res * half_res * a;
  }
}

int main() {
  cout << power(3, 3) << endl;
  return 0;
}