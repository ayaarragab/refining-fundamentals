#include "input_funcs.h"

int n_power_m(int n, int m) {
  if (m == 1)
    return n;
  return n * n_power_m(n, m - 1);
}

int main() {
  cout << n_power_m(4, 2) << endl;
  return 0;
}