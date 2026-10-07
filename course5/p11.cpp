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

void is_palindrome(int num) {
    if (reverse(num) == num)
        cout << "Palindrome\n";
    else
        cout << "Not palindrome\n";
}

int main() {
    is_palindrome(readNum("Enter a number:\n"));
    return 0;
}
