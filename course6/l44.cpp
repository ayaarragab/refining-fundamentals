#include "input_funcs.h"
using namespace input_funcs;


int main() {
  int num = input_funcs::readNum("Enter number of elements of the array");

  int *ptr;
  ptr = new int[num];
  for (int i = 0; i < num; i++)
  {
    int n = input_funcs::readNum("Enter a number");
    *(ptr + i) = n;
  }

  for (int i = 0; i < num; i++)
    cout << *(ptr + i) << endl;
  
  delete[] ptr;
  return 0;
}