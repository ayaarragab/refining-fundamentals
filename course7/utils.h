#include <iostream>
using namespace std;

namespace utils
{
  int random(int from, int to) {
      return rand() % (to - from + 1) + from;
  }
  void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
  }
}

