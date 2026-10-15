#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector <short> vNums = { 1, 2, 3, 4, 5 };
  for (short &num : vNums)
    cout << num << endl;
  
  return 0;
}