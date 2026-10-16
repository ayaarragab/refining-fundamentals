#include <iostream>
using namespace std;

namespace utils
{
  int random(short from, short to) {
      return rand() % (to - from + 1) + from;
  } 
}

