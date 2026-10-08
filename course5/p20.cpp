#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(short from, short to) {
    return rand() % (to - from + 1) + from;
}

char get_random_small_letter() {
  return char(random(97, 123));
}

char get_random_capital_letter() {
  return char(random(65, 91));
}

char get_random_special_character() {
  return char(random(32, 48));
}

char get_random_digit() {
  return char(random(48, 58));
}


int main() {
    srand((unsigned)time(NULL));
    cout << get_random_capital_letter() << endl;
    cout << get_random_digit() << endl;
    cout << get_random_small_letter() << endl;
    cout << get_random_special_character() << endl;
}