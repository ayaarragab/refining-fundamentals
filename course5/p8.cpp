#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

short get_last_digit_and_trancuate(int &num) {
  short d = num % 10;
  num /= 10;
  return d;
}

void decide_based_on_quality(int d, int freq_n, int &freq) {
    if (d == freq_n)
        freq += 1;
}

void print_result(int num, int freq_n) {
    int freq = 0;
    while (num > 0)
    {
        int d = get_last_digit_and_trancuate(num);
        decide_based_on_quality(d, freq_n, freq);
    }
    cout << freq << "\n";
}

int main() {
    int num = readNum("Enter a postitve number:\n");
    int freq = readNum("Enter a number to count:\n");
    print_result(num, freq);
    return 0;
}

