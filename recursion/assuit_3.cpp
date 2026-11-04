#include <bits/stdc++.h>
using namespace std;

void NToOne(int n) {
    if (n == 0)
        return;

    cout << n << "\n";
    NToOne(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    NToOne(n);
    return 0;
}
