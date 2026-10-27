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
    
    clsAddress(string AddressLine1, string AddressLine2, string City, string Country) {
      this->AddressLine1 = AddressLine1;
      this->AddressLine2 = AddressLine2;
      this->City = City;
      this->Country = Country;
    }

    static void Print(clsAddress addr)
    {
      cout << "\nAddress:\n";
      cout << addr.AddressLine1 << endl;
      cout << addr.AddressLine2 << endl;
      cout << addr.City << endl;
      cout << addr.Country << endl;
    }
    void callPrintAddress() {
      Print(*this);
    }
  };

public:
  string FullName;
  clsAddress Address = clsAddress("", "", "", "");
  clsPerson()
  {
    this->Address = clsAddress(" 10", "Queen Rania Street", "Amman", "Jordan");
    FullName = "Mohammed Abu-Hadhoud";
  }
};

int main()
{
  clsPerson Person1;
  Person1.Address.callPrintAddress();
  return 0;
}