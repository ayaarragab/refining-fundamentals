#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

void inverted_number_pattern(int num) {
    for (short i = num; i > 0; i--)
    {
        for (short j = 0; j < i; j++)
            cout << i;
        cout << "\n";
    }
    
}

int main() {
    inverted_number_pattern(readNum("Enter a number:\n"));
    return 0;
}
