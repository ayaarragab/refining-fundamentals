#include "input_funcs.h"
#include <cctype>

void count_capital_and_small(string str, int &cap, int &small) {
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
            ++cap;
        if (islower(str[i]))
            ++small;
    }
}

int main() {
    int small = 0, cap = 0;
    string str = input_funcs::readString("Please enter a string");
    count_capital_and_small(str, cap, small);
    cout << small;
    cout << cap;
    return 0;
}
