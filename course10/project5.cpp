#include <iostream>
#include "clsDate.h"


using namespace std;

int main() {
  clsDate d1 = clsDate("1", "1", "2026");
  clsDate d2 = clsDate("2", "2", "2026");
  cout << d1.date_to_str() << endl;  
  cout << d1.date_to_str() << endl;  
  cout << d1.date1_before_date2(d2) << endl;
  return 0;
}