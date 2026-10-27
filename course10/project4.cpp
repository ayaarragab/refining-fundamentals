#include "clsString.h"


int main() {
  clsString str = clsString("Aya Ragab");
  cout << str.replace_word("Ragab", "R.") << endl;
  cout << clsString::replace_word("Aya Ragab", " ", "Ragab", "R.") << endl;

  return 0;
}