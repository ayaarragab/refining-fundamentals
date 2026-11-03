#include <iostream>
using namespace std;

template <typename T> T max_(T num1, T num2) {
  return max(num1, num2);
}

int main() {
  cout << max_<int>(1, 2) << endl;
  cout << max_<float>(1.5, 2.5) << endl;
  return 0;
}