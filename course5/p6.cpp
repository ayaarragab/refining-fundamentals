#include <iostream>
using namespace std;

int readNum() {
    int n;
    cout << "Enter a number\n";
    cin >> n;
    return n;
}

short get_last_digit_and_trancuate(int &num) {
  short d = num % 10;
  num /= 10;
  return d;
}

void print_result(int num) {
  short sum = 0;
  while (num != 0)
    {
        short d = get_last_digit_and_trancuate(num);
        sum += d;
    }
    cout << sum << "\n";
}

int main() {
    int num = readNum();
    print_result(num);
    return 0;
}