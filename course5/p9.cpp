#include <iostream>
using namespace std;

int readNum(string message)
{
  int n;
  cout << message;
  cin >> n;
  return n;
}

bool has_digit(char d, string num) {
  for (short i = 0; i < num.length(); i++)
  {
    if (d == num[i])
      return true;  
  }
  return false;
}

string get_unique_digits(string num) {
  string unique_d = "";
  for (size_t i = 0; i < num.length(); i++)
  {
    if (!has_digit(num[i], unique_d))
      unique_d += num[i];
  }
  return unique_d;
}

short get_last_digit_and_trancuate(int &num) {
  short d = num % 10;
  num /= 10;
  return d;
}

void compare(short to_compare_with, int num) {
  short freq = 0;
  while (num > 0)
  {
    short d = num % 10;
    if (d == to_compare_with)
      freq += 1;
    num /= 10;
  }
  cout << "Frequency of Digit " << to_compare_with << " is " << freq << " \n";
}

void get_frequency_of_each_digit(int unqiue_d, int num) {
  while (unqiue_d > 0)
  {
    short to_compare_with = get_last_digit_and_trancuate(unqiue_d);
    compare(to_compare_with, num);
  }
  
}

void determine_each_digit_freqency(int num) {
  string num_str = to_string(num);
  string unique_digits = get_unique_digits(num_str);
  get_frequency_of_each_digit(stoi(unique_digits), stoi(num_str));
}

int main()
{
  int num = readNum("Enter a postitve number:\n");
  determine_each_digit_freqency(num);
  return 0;
}
