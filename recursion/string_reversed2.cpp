#include <iostream>

using namespace std;


void reverse(int idx, string word) {
    if (idx == word.length())
        return;

    reverse(idx + 1, word);
    cout << word[idx] << endl;
}

int main() {
  string word = "ABCD";
  reverse(0, word);
  return 0;
}