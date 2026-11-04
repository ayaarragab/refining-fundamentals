#include <bits/stdc++.h>
using namespace std;

void ILoveRecursion(int num) {
  if (num == 0)
    return;
  cout << "I love Recursion" << "\n";
  ILoveRecursion(num - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;
    ILoveRecursion(num);
    return 0;
}