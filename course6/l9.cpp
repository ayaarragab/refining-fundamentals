#include "input_funcs.h"
using namespace std;

int main() {
  int num = input_funcs::readNum("Enter a number");
  num == 0 ? std::cout << "Num is 0\n" : num > 0 ? std::cout << "Num > 0\n" : std::cout << "Num < 0\n";
  return 0;
}