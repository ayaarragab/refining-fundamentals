#include <iostream>
using namespace std;

enum  enRandomType { SmallLetter, CapitalLetter, SpecialLetter, Digit };


int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}


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

string generate_4_char_string() {
    string word = "";
    word.append(1, get_random_type(enRandomType::CapitalLetter));
    word.append(1, get_random_type(enRandomType::CapitalLetter));
    word.append(1, get_random_type(enRandomType::CapitalLetter));
    word.append(1, get_random_type(enRandomType::CapitalLetter));
    return word;
}

string generate_key() {
    string key = "";
    key.append(generate_4_char_string());
    key.append(1, '-');
    key.append(generate_4_char_string());
    key.append(1, '-');
    key.append(generate_4_char_string());
    key.append(1, '-');
    key.append(generate_4_char_string());
    return key;
}

void generate_keys(short n) {
    for (short i = 1; i <= n; i++)
        cout << "Key [" << i << "]: " << generate_key() << endl;
}

int main() {
    generate_keys(readNum("Enter number of keys do you want:\n"));
    return 0;
}
