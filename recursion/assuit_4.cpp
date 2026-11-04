#include <bits/stdc++.h>
using namespace std;


void handleEnding(int num, bool firstTime) {
    if (firstTime)
        cout << num % 10 << "\n";   
    else
        cout << num % 10 << " ";
}

void printDigits(int num, bool firstTime=true) {
    if (!num) {
        if (firstTime)
            cout << 0 << '\n';
        return;
    }
    
    printDigits(num / 10, false);
    handleEnding(num, firstTime);
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
        printDigits(n);
        --iterations;
    }
    
    return 0;
}
