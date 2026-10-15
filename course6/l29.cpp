#include <vector>
#include "input_funcs.h"
#include "print_funcs.h"
using namespace input_funcs;
using namespace print_funcs;



void loop_untill_finish(vector <int> &vNums) {
  bool enter_again = true;
  
  while (enter_again)
  {
    int num = readNum("Enter a number to add to the vector:");
    vNums.push_back(num);
    enter_again = input_funcs::wants_to_enter();
  }
}

int main() {
  vector <int> vNums;
 
  loop_untill_finish(vNums);
 
  print_funcs::print_vector_int(vNums);
  
  return 0;
}