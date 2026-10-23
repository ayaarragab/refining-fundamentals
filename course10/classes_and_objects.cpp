#include <iostream>
using namespace std;


class clsPerson {
  private:
    string _first_name;
    string _last_name;
  
  public:
    void setFirstName(string firstName) {
      _first_name = firstName;
    }
    string getFirstName() {
      return _first_name;
    }
    void setLastName(string lastname) {
      _last_name = lastname;
    }
    string getLastName() {
      return _last_name;
    }
};

int main() {
  clsPerson p;
  return 0;
}