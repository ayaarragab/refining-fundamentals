#include <iostream>

using namespace std;


void fill_array(short arr[10][10]) {
  for (short i = 1; i <= 10; i++)
  {
    for (short j = 1; j <= 10; j++)
      arr[i - 1][j - 1] = i * j;
  }
}

void print_array(short arr[10][10]) {
  for (short i = 0; i < 10; i++)
  {
    for (short j = 1; j <= 10; j++)
      printf("%0*d ", 2, i * j);
    cout << "\n";
  }
}


int main() {
  short arr[10][10];
  fill_array(arr);
  print_array(arr);
  return 0;
}