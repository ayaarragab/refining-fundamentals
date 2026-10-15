#include <iostream>
using namespace std;


int main() {
  int x = 10, b = 15;
  int * p = &x;
  int &a = x;

  cout << x << endl;
  cout << p << endl;
  cout << a << endl;

  cout << endl;
  
  cout << &x << endl;
  cout << &p << endl;
  cout << &a << endl;

  cout << endl;



  cout << *p << endl;

  return 0;
}