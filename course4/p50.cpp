#include <iostream>
using namespace std;

bool is_correct() {
  short pin;
  bool is_correct = false;
  short i = 0;
  do
  {
    cout << "Enter PIN\n";
    cin >> pin;
    is_correct = (pin == 1234);
    ++i;
  } while (!is_correct && i < 3);
  return is_correct;
}

void printBasedOnPIN() {
  bool res = is_correct();
  if (res)
    cout << "You entered the correct one\n";
  else
    cout << "You consumed the 3 trails";
}

int main() {
  printBasedOnPIN();
  return 0;
}