#include <iostream>

using namespace std;


int sumArray(int idx, int array[5]) {
  if (idx < 0)
    return 0;
  
  return array[idx] + sumArray(idx - 1, array);
}

int main() {
  int array[5] = { 1, 2, 3, 4, 5 };
  cout << sumArray(4, array) << endl;
  return 0;
}