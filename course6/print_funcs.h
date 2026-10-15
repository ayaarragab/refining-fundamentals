#include <iostream>
#include <vector>
using namespace std;
namespace print_funcs {
  void print_vector_int(vector <int> v) {
    for (int &num : v)
      cout << num << endl;
  }
}