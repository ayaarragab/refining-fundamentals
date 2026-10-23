#include <iostream>
using namespace std;


class clsPerson {
  private:
    string _first_name;
    string _last_name;
  
  public:
    void set_full_name(string first_name, string last_name) {
        _last_name = last_name;
        _first_name = first_name;
    }
    string get_fullName() {
        return _first_name + " " + _last_name;
      }
};

int main() {
  clsPerson p;
  p.set_full_name("Aya", "R.");
  p.get_fullName();
  cout << p.get_fullName() << endl;
  return 0;
}