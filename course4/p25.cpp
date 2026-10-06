#include <iostream>
using namespace std;


int readNum() {
  int num;
  cout << "Enter a number \n";
  cin >> num;
  return num;
}


bool is_valid(int num) {
  return num >= 18 && num <= 45;
}


bool decide(bool valid) {
  if (valid) {
    cout << "Valid\n";
    return true;
  }
  else {
    cout << "Not valid. Exiting!\n";
    return false;
  }
}

void loop_untill_not_valid() {
  bool result;
  do
  {
    int num = readNum();
    result = decide(is_valid(num));
  } while (result);
}

int main() {
  loop_untill_not_valid();
}