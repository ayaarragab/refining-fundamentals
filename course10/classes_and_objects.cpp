#include <iostream>
using namespace std;


class clsPerson {
  public:
    string first_name;
    string last_name;
    string get_fullName() {
      return first_name + " " + last_name;
    }
};

int main() {
  clsPerson p;
  p.first_name = "Aya";
  p.last_name = "R.";

  cout << p.get_fullName() << endl;
  return 0;
}