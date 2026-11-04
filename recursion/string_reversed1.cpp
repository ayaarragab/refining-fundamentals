#include <iostream>

using namespace std;


string reverse(int from, int to, string word) {
    if (from >= to)
        return "";

    return word[to - 1] + reverse(from, to - 1, word);
}

int main() {
  string word = "ABCD";
  word = reverse(0, word.length(), word);
  cout << word << endl;
  return 0;
}