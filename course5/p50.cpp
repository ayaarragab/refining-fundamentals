#include <iostream>
#include <cmath>
using namespace std;

float readNum(string message) {
    float n;
    cout << message;
    cin >> n;
    return n;
}

short my_sqrt(float num) {
    for (short i = 0; i < num / 2; i++)
    {
        if (i * i == num)
            return i;   
    }
    return 0.0;
}

int main() {
    float num = readNum("Enter number:\n");
    cout << "C++ sqrt()" << sqrt(num) << "\n";
    cout << "My sqrt()" << my_sqrt(num) << "\n";
    return 0;
}
