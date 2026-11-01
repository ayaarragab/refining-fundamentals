#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:
  static void _UpdateClientInfo(clsBankClient &client)
  {
    string FirstName = clsInput::readStringOptional("Enter client First Name", "First Name");
    string LastName = clsInput::readStringOptional("Enter client Last Name", "Last Name");
    string Email = clsInput::readStringOptional("Enter client Email", "Enter client Email");
    string Phone = clsInput::readStringOptional("Enter client Phone", "Phone");
    string PinCode = clsInput::readStringOptional("Enter the Pin Code", "Pin Code");
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

  static void _PrintClientInfo(clsBankClient client)
  {
    cout << "Account Name: " << client.GetFirstName() + " " + client.GetLastName() << endl;
    cout << "Account Phone: " << client.GetPhone() << endl;
    cout << "Account Email: " << client.GetEmail() << endl;
    cout << "Account Number: " << client.GetAccountNumber() << endl;
    cout << "Account Balance: " << client.getAccountBalance() << endl;
    cout << "Account Pin Code: " << client.GetPinCode() << endl;
  }

public:
  static void ShowUpdateClient()
  {
    string AccountNumber = clsInput::readString("Enter account Number");

    clsBankClient client = clsBankClient::Find(AccountNumber);

    while (client.IsEmpty())
    {
      cout << "No Client Exists with this Account Number" << endl;
      AccountNumber = clsInput::readString("Enter account Number");
      client = clsBankClient::Find(AccountNumber);
    }

    _UpdateClientInfo(client);

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
};
