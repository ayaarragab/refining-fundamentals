#include "input_funcs.h"
#include <cctype>

string lower_title(string str) {
    str[0] = tolower(str[0]);
    for (short i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == ' ')
            str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    string str = input_funcs::readString("Enter a string");
    cout << lower_title(str) << endl;
    return 0;
}
