#include "input_funcs.h"
#include <cctype>

char swapcase(char &c) {
    return isupper(c) ? tolower(c) : toupper(c);
}


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
    char c = input_funcs::readCharacter("Please enter a character");
    
    cout << "Letter " << c << " found exactly " << count_c(str, c) << " Time(s)\n";
    cout << "Letter " << c << " Or " << swapcase(c) << " found exactly " << count_c(str, c) + count_c(str, swapcase(c)) << " Time(s)\n";
    return 0;
}
