#include <iostream>
#include <cmath>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

short my_abs(short num) {
    if (num < 0)
        num *= -1;
    return num;
}

int main() {
    int num = readNum("Enter number:\n");
    cout << "C++ ABS()" << abs(num) << "\n";
    cout << "My ABS()" << my_abs(num) << "\n";
    return 0;
}
