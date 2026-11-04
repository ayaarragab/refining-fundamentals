#include <bits/stdc++.h>
using namespace std;

string stars(int num, int fixed)
{
    if (num == 0)
        return "";
    int diff = (fixed - num) / 2;
    string s = string(diff, ' ');
    
    for (short i = 0; i < num; i++)
        s.append("*");
    return s;
}

string printPyramids(int num, int fixed)
{
    if (num == 1)
        return stars(1, fixed);
    return printPyramids(num - 1, fixed) + "\n" + stars((num - 1) + num, fixed);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string pyramid = printPyramids(n, (n - 1) + n);
    cout << pyramid << endl;
    return 0;
}