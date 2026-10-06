#include <iostream>
#include <string>
using namespace std;


int main() {
  for (short i = 0; i < 12; i++)
  {
    cout << i << " Multiplication table\n";
    for (short j = 0; j < 12; j++)
    {
      cout << i << " * " << j << "= " << i * j << "\n"; 
    }
    cout << "=========================\n";
  }
  return 0;
}