#include <bits/stdc++.h>
using namespace std;

void OneToN(int n) {
    if (n == 0)
        return;

    OneToN(n - 1);
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    OneToN(n);
    return 0;
}
