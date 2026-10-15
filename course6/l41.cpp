#include <iostream>
using namespace std;



int main() {
  void *ptr;
  short x = 1;
  float y = 2.2;
  ptr = &x;
  
  cout << *(static_cast<short*>(ptr)) << endl;
  
  ptr = &y;
  cout << *(static_cast<float*>(ptr)) << endl;

  return 0;
}