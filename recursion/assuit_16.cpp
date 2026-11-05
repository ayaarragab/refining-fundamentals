#include <bits/stdc++.h>
using namespace std;

int floorLog2N(long long n) {
    if (n == 1)
        return 0;
    
    return 1 + floorLog2N(n / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long num;
    cin >> num;
    cout << floorLog2N(num) << endl;

    return 0;
}
