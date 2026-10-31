#include "clsBankClient.h"
#include "clsInput.h"
#include <iostream>
using namespace std;

void ReadClientInfo(clsBankClient &client) {
  string FirstName = clsInput::readString("Enter client First Name");
  string LastName = clsInput::readString("Enter client Last Name");
  string Email = clsInput::readString("Enter client Email");
  string Phone = clsInput::readString("Enter client Phone");
  string PinCode = clsInput::readString("Enter the Pin Code");
  if (FirstName.length() != 0)
    client.SetFirstName(FirstName);
  if (LastName.length() != 0)
    client.SetLastName(LastName);
  if (Email.length() != 0)
    client.SetEmail(Email);
  if (Phone.length() != 0)
    client.SetPhone(Phone);
  if (PinCode.length() != 0)
    client.setPinCode(PinCode);
}

void UpdatClient() {
  string AccountNumber = clsInput::readString("Enter account Number");
  
  clsBankClient client = clsBankClient::Find(AccountNumber);
  
  while (client.IsEmpty()) {
    cout << "No Client Exists with this Account Number" << endl;
    AccountNumber = clsInput::readString("Enter account Number");
    client = clsBankClient::Find(AccountNumber);
  }
  
  ReadClientInfo(client);

  clsBankClient::enSaveResults result = client.Save();
}

int main() {
  clsBankClient client = clsBankClient::Find("A0121");
  client.Print();
  
  clsBankClient client2 = clsBankClient::Find("A0121", "324343");
  client2.Print();

  return 0;
}