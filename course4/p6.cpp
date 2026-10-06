#include <iostream>
using namespace std;

struct stInfo
{
  string firstName;
  string lastName;
};

void readInfo (stInfo &s) {
  cout << "Enter first name\n";
  cin >> s.firstName;
  cout << "Enter last name\n";
  cin >> s.lastName;
}

void concatenateName(stInfo s, bool isRev) {
  if (isRev)
    cout << s.lastName + " " + s.firstName << "\n";
  else
    cout << s.firstName + " " + s.lastName << "\n";
}

int main()
{
  stInfo s;
  readInfo(s);
  concatenateName(s, true);
  return 0;
}