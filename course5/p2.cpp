#include <iostream>
#include <cmath>
using namespace std;

void is_already_prime(short n) {
    if (n == 2)
       cout << n << "\n";
}
bool is_prime(short n) {
    short half_n = floor(n / 2);
    for (short i = 2; i <= half_n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

short readNum() {
    short n;
    cout << "Enter a number\n";
    cin >> n;
    return n;
}


void run() {
    int num = readNum();
    is_already_prime(num);
    for (short i = 2; i < num; i++)
    {
        if (is_prime(i))
            cout << i << "\n";
    }
    
}

int main() {
    run();
    return 0;
}
