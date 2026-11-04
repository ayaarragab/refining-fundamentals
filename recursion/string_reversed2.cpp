#include <iostream>

using namespace std;


string reverse(int idx, string word) {
    if (idx < 0)
        return "";

    return word[idx] + reverse(idx - 1, word);
}

int main() {
  string word = "ABCD";
  word = reverse(word.length(), word);
  cout << word << endl;
  return 0;
}