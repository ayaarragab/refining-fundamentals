#include <bits/stdc++.h>
using namespace std;

string stars(int num) {
    if (num == 0)
        return "";
    
    return "*" + stars(num - 1);
}

string printPyramids(int num) {
    if (num == 1)
        return "*";
    return printPyramids(num - 1) + "\n" + stars((num - 1) + num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string pyramid = printPyramids(3);
    cout << pyramid << endl;
    return 0;
}
