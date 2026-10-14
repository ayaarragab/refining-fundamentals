#include <iostream>

namespace input_funcs {
  void print_input_message(std::string message) {
    std::cout << message << std::endl;
  }
  int readNum(std::string message) {
    print_input_message(message);
    int num;
    std::cin >> num;
    return num;
  }
}