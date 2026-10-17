#include <iostream>
using namespace std;


void fib(short n) {
    int prev1 = 0, prev2 = 1;
    int result;
    cout << "1  ";
    for (short i = 0; i < n - 1; i++)
    {
        result = prev1 + prev2;
        cout << result << "  ";
        prev1 = prev2;
        prev2 = result;
    }
    cout << endl;
}

int main() {
    fib(10);
    return 0;
}
