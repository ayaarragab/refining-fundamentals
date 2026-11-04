#include <iostream>

using namespace std;


int pascale_triangle(int r, int c) {
  if (c == 0 || c == r)
    return 1;
  
  return pascale_triangle(r - 1, c) + pascale_triangle(r - 1, c - 1);
}

int main() {
  cout << pascale_triangle(4, 3) << endl;
  return 0;
}