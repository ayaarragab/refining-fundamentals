#include <bits/stdc++.h>
using namespace std;

int even_behavior(int num) {
  return num / 2;
}

int odd_behavior(int num) {
  return (num * 3) + 1;
}

int decide(int num) {
  bool isEven = ((num & 1) == 0);
  switch (isEven)
  {
  case false:
    return odd_behavior(num);
  case true:
    return even_behavior(num);
  }
}

int collatz_conjecture(int num) {
  if (num == 1)
    return 1;

  return 1 + collatz_conjecture(decide(num));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int num;
  cin >> num;
  cout << collatz_conjecture(num) << endl;
  return 0;
}