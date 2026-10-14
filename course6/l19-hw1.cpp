#include "input_funcs.h"

void print_from_m_to_n(int n, int m) {
  if(m >= n)
  {
    cout << m << endl;
    print_from_m_to_n(n, m - 1);
  }
}

int main() {
  print_from_m_to_n(1, 6);
  return 0;
}