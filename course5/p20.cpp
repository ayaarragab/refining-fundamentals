#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
enum  enRandomType { SmallLetter, CapitalLetter, SpecialLetter, Digit };

int random(short from, short to) {
    return rand() % (to - from + 1) + from;
}

char get_random_type(enRandomType type) {
  switch (type)
  {
    case enRandomType::CapitalLetter:
      return char(random(65, 90));
    case enRandomType::SmallLetter:
      return char(random(97, 122));
    case enRandomType::SpecialLetter:
      return char(random(33, 47));
    case enRandomType::Digit:
      return char(random(48, 57));
    default:
      break;
  }
  return ' ';
}

int main() {
    srand((unsigned)time(NULL));
    cout << get_random_type(enRandomType::CapitalLetter) << endl;
}