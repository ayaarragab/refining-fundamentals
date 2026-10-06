#include <iostream>
#include <cmath>

using namespace std;

int readNum() {
  int num;
  cout << "Enter a number \n";
  cin >> num;
  return num;
}

bool is_divisible(short n, short i) {
  return n % i == 0;
}

bool isPrime (int n) {
  for (short i = 2; i < floor(n / 2); i++)
  {
    if (is_divisible(n, i))
      return false;
  }
  return true;
}

void print_result(bool is_prime) {
  if (is_prime)
    cout << "prime\n";
  else
    cout << "Not prime\n";
}

int main() {
  print_result(isPrime(readNum()));
  return 0;
}