#include "input_funcs.h"

char swapcase(char &c) {
    if (c > 64 && c < 91)
        c += 32;
    if (c > 96 && c < 123)
        c -= 32;
    return c;
}

int main() {
    char c = input_funcs::readCharacter("Please enter a character");
    cout << swapcase(c) << endl;
    return 0;
}
