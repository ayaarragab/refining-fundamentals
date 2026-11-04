#include <bits/stdc++.h>
using namespace std;

long long factorial(int num)
{
  if (num == 1 || num == 0)
    return 1;
  return num * factorial(num - 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int num;
  cin >> num;
  cout << factorial(num) << "\n";
  return 0;
}