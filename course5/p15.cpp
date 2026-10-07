#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

void letter_pattern(int num) {
    for (short i = 65; i <= 65 + num; i++)
    {
        for (short j = 1; j <= (i - 64); j++)
            cout << char(i);
        cout << "\n";
    }
}

int main() {
    letter_pattern(readNum("Enter a number:\n"));
    return 0;
}
