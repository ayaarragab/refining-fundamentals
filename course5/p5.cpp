#include <iostream>
using namespace std;

int readNum() {
    int n;
    cout << "Enter a number\n";
    cin >> n;
    return n;
}


int get_last_digit_and_trancuate(int &num) {
  int d = num % 10;
  cout << d << "\n";
  num /= 10;
  return d;
}

void print_result(int num) {
  while (num != 0)
    get_last_digit_and_trancuate(num);
}

int main() {
    int num = readNum();
    print_result(num);
    return 0;
}
