#include <iostream>
using namespace std;

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

string generate_4_char_string(short length, enRandomType type) {
    string word = "";
    for (short i = 0; i < length; i++)
        word.append(1, get_random_type(type));
    return word;
}

string generate_key(short word_length, enRandomType type) {
    string key = "";
    for (short i = 0; i < 4; i++)
    {
        key.append(generate_4_char_string(word_length, type));
        if (i != 3)
            key.append(1, '-');
    }
    
    return key;
}

void fill_array_with_keys(string array[], short len) {
    for (short i = 0; i < len; i++)
        array[i] = generate_key(4, enRandomType::CapitalLetter);
}

void print_array_content(string array[], short len) {
    for (short i = 0; i < len; i++)
        cout << "Array[" << i + 1 << "]: " << array[i] << "\n";
}

int main() {
    short len = readNum("Enter length of the array:\n");
    string keys[len];
    fill_array_with_keys(keys, len);
    print_array_content(keys, len);
    return 0;
}
