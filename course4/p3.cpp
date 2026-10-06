#include <iostream>
using namespace std;

void readNum(short &num) {
  cout << "Enter a number\n";
  cin >> num;
}

bool check_even_or_odd(short num) {
  return num % 2 == 0;
}

void print_based_on_result(short num) {
  bool result = check_even_or_odd(num);
  if (result)
    cout << "Even\n";
  else
    cout << "Odd\n";
}

int main() {
  short num;
  readNum(num);
  print_based_on_result(num);
  return 0;
}