#include <bits/stdc++.h>
using namespace std;

void handleEnding(int num, bool firstTime) {
    if (firstTime)
        cout << num % 2 << "\n";   
    else
        cout << num % 2;
}

void decimalToBinary(int num, bool firstTime=true) {
    if (num == 0)
    {
        if (firstTime)
        {
            cout << num % 2 << "\n"; 
            return;
        }
        return;
    }
    
    decimalToBinary(num / 2, false);
    handleEnding(num % 2, firstTime);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int iterations;
    cin >> iterations;
    while (iterations)
    {
        int n;
        cin >> n;
        decimalToBinary(n);
        --iterations;
    }
    return 0;
}
