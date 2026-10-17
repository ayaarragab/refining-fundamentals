#include "input_funcs.h"
#include <cctype>

int count_c(string str, char c) {
    int count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
            ++count;
    }
    return count;
}

int main() {
    string str = input_funcs::readString("Please enter a string");
    cout << count_c(str, 'c');
    return 0;
}
