#include "input_funcs.h"
#include <cctype>

string lower(string str) {
    for (short i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

string upper(string str) {
    for (short i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}
int main() {
    string str = input_funcs::readString("Enter a string");
    cout << "Lower case: " << lower(str) << endl;
    cout << "Upper case: " << upper(str) << endl;
    return 0;
}
