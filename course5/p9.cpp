#include <iostream>
using namespace std;

int readNum(string message)
{
  int n;
  cout << message;
  cin >> n;
  return n;
}

void determine_each_digit_freqency(int num) {}

int main()
{
  int num = readNum("Enter a postitve number:\n");
  determine_each_digit_freqency(num);
  return 0;
}
