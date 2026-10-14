#include "input_funcs.h"

int main() {
  int num = input_funcs::readNum("Enter a number");
  num > 0 ? std::cout << "Positive\n" : std::cout << "Negative\n";
  return 0;
}