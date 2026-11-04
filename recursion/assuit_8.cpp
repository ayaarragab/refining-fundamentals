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

string printPyramids(int start, int num, int fixed)
{
    if (start > num)
        return "";
    if (start == num)
        return printPyramids(start + 1, num, fixed) + stars((start - 1) + start, fixed);
    
    return printPyramids(start + 1, num, fixed) + "\n" + stars((start - 1) + start, fixed);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string pyramid = printPyramids(1, n, (n - 1) + n);
    cout << pyramid << endl;
    return 0;
}