#include "input_funcs.h"
#include <cctype>

string title(string str) {
    str[0] = toupper(str[0]);
    for (short i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == ' ')
            str[i] = toupper(str[i]);
    }
    return str;
}

int main() {
    string str = input_funcs::readString("Enter a string");
    cout << title(str) << endl;
    return 0;
}
