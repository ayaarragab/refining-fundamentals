#include <iostream>
using namespace std;



int main() {
  short *ptr;
  
  ptr = new short;

  *(ptr) = 10; 
  delete ptr;
  return 0;
}