#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  time_t t = time(0);
  tm *local = localtime(&t);
  cout << local->tm_zone << endl;
  cout << local->tm_hour << endl;
  cout << local->tm_wday << endl;
  cout << local->tm_yday << endl;
}