#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> stk;
    stk.push(12);
    stk.push(13);
    stk.push(14);
    stk.push(15);
    cout << stk.top() << endl;
    cout << stk.size() << endl;
    return 0;
}
