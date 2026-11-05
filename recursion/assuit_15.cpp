#include <bits/stdc++.h>
using namespace std;

int fib(int num) {
    if (num == 1)
        return 0;
    if (num == 2)
        return 1;
    return fib(num - 1) + fib(num - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    cin >> num;
    cout << fib(num) << "\n";
    return 0;
}
