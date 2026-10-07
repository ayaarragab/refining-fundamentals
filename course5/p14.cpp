#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

void inverted_letter_pattern(int num) {
    int k = num;
    for (short i = num + 64; i > 64; i--)
    {
        for (short j = 1; j <= k; j++)
            cout << char(i);
        --k;
        cout << "\n";
    }
    
}

int main() {
    inverted_letter_pattern(readNum("Enter a number:\n"));
    return 0;
}
