#include "input_funcs.h"
#include <cctype>

char swapcase(char &c) {
    return isupper(c) ? tolower(c) : toupper(c);
}

string swapcase_str(string str) {
    for (short i = 0; i < str.length(); i++)
        str[i] = swapcase(str[i]);
    return str;
}

int main() {
    string str = input_funcs::readString("Please enter a string");
    cout << swapcase_str(str) << endl;
    return 0;
}
