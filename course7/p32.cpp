#include "input_funcs.h"

bool is_vowel(char c) {
    char vowels[] = { 'a', 'i', 'u', 'y', 'o' };
    for (short i = 0; i < 5; i++)
    {
        if (tolower(c) == vowels[i])
            return true; 
    }
    return false;
}

int main() {
    char c = input_funcs::readCharacter("Please enter a character");
    cout << is_vowel(c) << endl;
    return 0;
}
