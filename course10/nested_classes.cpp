// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;
class clsPerson
{
  class clsAddress
  {
  public:
    string AddressLine1;
    string AddressLine2;
    string City;
    string Country;
    
    clsAddress(string AddressLine1_, string AddressLine2_, string City_, string Country_) {
      AddressLine1 = AddressLine1_;
      AddressLine2 = AddressLine2_;
      City = City_;
      Country = Country_;
    }

    void Print()
    {
      cout << "\nAddress:\n";
      cout << AddressLine1 << endl;
      cout << AddressLine2 << endl;
      cout << City << endl;
      cout << Country << endl;
    }
  };

public:
  string FullName;
  clsAddress Address = clsAddress("", "", "", "");
  clsPerson()
  {
    Address = clsAddress(" 10", "Queen Rania Street", "Amman", "Jordan");
    FullName = "Mohammed Abu-Hadhoud";
  }
};

int main()
{
  clsPerson Person1;
  Person1.Address.Print();
  system("pause>0");
  return 0;
}