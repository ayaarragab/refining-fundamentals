#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  time_t t = time(0);
  char *str_t = ctime(&t);
  cout << "Egypt time is" << str_t;
  tm* gmt_t = gmtime(&t);
  str_t = asctime(gmt_t);
  cout << "Egypt time is in gmt is" << str_t;
  return 0;
}