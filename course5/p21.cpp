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

string generate_4_char_string(short length) {
    string word = "";
    for (short i = 0; i < length; i++)
        word.append(1, get_random_type(enRandomType::CapitalLetter));
    return word;
}

string generate_key(short word_length, short key_length) {
    string key = "";
    for (short i = 0; i < key_length; i++)
    {
        key.append(generate_4_char_string(word_length));
        if (i != key_length - 1)
            key.append(1, '-');
    }
    
    return key;
}

void generate_keys(short n, short word_length, short key_length) {
    for (short i = 1; i <= n; i++)
        cout << "Key [" << i << "]: " << generate_key(word_length, key_length) << endl;
}

int main() {
    generate_keys(readNum("Enter number of keys do you want:\n"), 4, 4);
    return 0;
}
