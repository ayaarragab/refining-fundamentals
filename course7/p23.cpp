#include "input_funcs.h"

void print_first_letter_of_each_word(string str) {
    cout << str[0] << "  ";

    for (short i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == ' ')
            cout << str[i];
    }
    cout << endl;
}

int main() {
    string str = input_funcs::readString("Enter a string");
    print_first_letter_of_each_word(str);
    return 0;
}
