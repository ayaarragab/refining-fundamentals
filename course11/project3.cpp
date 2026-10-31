#include "clsBankClient.h"
#include "clsInput.h"
#include <iostream>
using namespace std;

void UpdateClientInfo(clsBankClient &client) {
  string FirstName = clsInput::readStringOtional("Enter client First Name", "First Name");
  string LastName = clsInput::readStringOtional("Enter client Last Name", "Last Name");
  string Email = clsInput::readStringOtional("Enter client Email", "Enter client Email");
  string Phone = clsInput::readStringOtional("Enter client Phone", "Phone");
  string PinCode = clsInput::readStringOtional("Enter the Pin Code", "Pin Code");
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


void ReadClientInfo(clsBankClient &client) {
  string FirstName = clsInput::readString("Enter client First Name");
  string LastName = clsInput::readString("Enter client Last Name");
  string Email = clsInput::readString("Enter client Email");
  string Phone = clsInput::readString("Enter client Phone");
  string PinCode = clsInput::readString("Enter the Pin Code");
  string Balance = clsInput::readString("Enter the Balance");
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
  if (Balance.length() != 0)
    client.setAccountBalance(stof(Balance));
}

void UpdateClient() {
  string AccountNumber = clsInput::readString("Enter account Number");
  
  clsBankClient client = clsBankClient::Find(AccountNumber);
  
  while (client.IsEmpty()) {
    cout << "No Client Exists with this Account Number" << endl;
    AccountNumber = clsInput::readString("Enter account Number");
    client = clsBankClient::Find(AccountNumber);
  }
  
  UpdateClientInfo(client);

  clsBankClient::enSaveResults result = client.Save();
  switch (result)
  {
  case clsBankClient::enSaveResults::svSuceeded:
    cout << "Succeeded!" << endl;
    break;

  case clsBankClient::enSaveResults::svFailedEmptyObject:
    cout << "Empty!" << endl;
    break;

  default:
    break;
  }
}

void AddClient() {
  string AccountNumber = clsInput::readString("Enter account Number");
  
  clsBankClient client = clsBankClient::Find(AccountNumber);
  
  while (!client.IsEmpty()) {
    cout << "This account number already in use" << endl;
    AccountNumber = clsInput::readString("Enter account Number");
    client = clsBankClient::Find(AccountNumber);
  }
  
  client = clsBankClient::getAddNewClient(AccountNumber);

  ReadClientInfo(client);

  clsBankClient::enSaveResults result = client.Save();
  
  switch (result)
  {
  case clsBankClient::enSaveResults::svSuceeded:
    cout << "Succeeded!" << endl;
    break;

  case clsBankClient::enSaveResults::svFailedAccountInUse:
    cout << "Account Already in use!" << endl;
    break;

  default:
    break;
  }
}

int main() {

  AddClient();

  return 0;
}