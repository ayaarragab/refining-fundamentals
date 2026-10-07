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
  string rev_num = "";
  while (num != 0)
    {
        short d = get_last_digit_and_trancuate(num);
        rev_num += to_string(d);
    }
    cout << stoi(rev_num) << "\n";
}

int main() {
    int num = readNum();
    print_result(num);
    return 0;
}
