#include <iostream>
using namespace std;

int main() {
  int grades[3];

  for (short i = 0; i < 3; i++)
  {
    cin >> grades[i];
  }
  for (short i = 0; i < 3; i++)
  {
    cout << grades[i];
  }
  return 0;
}