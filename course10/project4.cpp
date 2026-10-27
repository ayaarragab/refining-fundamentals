#include "csString.h"


int main() {
  csString str = csString("Aya Ragab");
  cout << str.replace_word("Ragab", "R.") << endl;
  cout << csString::replace_word("Aya Ragab", " ", "Ragab", "R.") << endl;

  return 0;
}