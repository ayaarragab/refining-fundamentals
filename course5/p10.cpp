#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

int get_last_digit_and_trancuate(int &num) {
  int d = num % 10;
  cout << d << "\n";
  num /= 10;
  return d;
}

int reverse(int num) {
  int rev_num = 0;
  while (num != 0)
    {
        short d = get_last_digit_and_trancuate(num);
        rev_num = ((rev_num * 10) + d);
    }
    return rev_num;
}

void print_result(int num) {
  while (num != 0)
    get_last_digit_and_trancuate(num);
}


int main() {
    print_result(reverse(readNum("Enter a number to print reversed:\n")));
    return 0;
}
