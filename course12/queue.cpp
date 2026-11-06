#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    return 0;
}
