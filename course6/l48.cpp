#include "input_funcs.h"
#include <vector>
using namespace input_funcs;


int main() {
  vector<short> nums = { 1, 2, 3, 4, 5 };
  vector<short>::iterator iter;

  for (iter = nums.begin(); iter != nums.end(); iter++)
    cout << *iter << endl;
  return 0;
}