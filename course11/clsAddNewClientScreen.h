#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen: protected clsScreen
{
  private:
    static void _ReadClientInfo(clsBankClient &client)
    {
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

    static void _PrintClientInfo(clsBankClient client) {
      cout << "Account Name: " << client.GetFirstName() + " " + client.GetLastName() << endl;
      cout << "Account Phone: " << client.GetPhone() << endl;
      cout << "Account Email: " << client.GetEmail() << endl;
      cout << "Account Number: " << client.GetAccountNumber() << endl;
      cout << "Account Balance: " << client.getAccountBalance() << endl;
      cout << "Account Pin Code: " << client.GetPinCode() << endl;
    }
  
  public:

    static void AddClient()
    {
      _DrawScreenHeader("Add New Client Screen");
      string AccountNumber = clsInput::readString("Enter account Number");

      clsBankClient client = clsBankClient::Find(AccountNumber);

      while (!client.IsEmpty())
      {
        cout << "This account number already in use" << endl;
        AccountNumber = clsInput::readString("Enter account Number");
        client = clsBankClient::Find(AccountNumber);
      }

      client = clsBankClient::getAddNewClient(AccountNumber);

      _ReadClientInfo(client);

      clsBankClient::enSaveResults result = client.Save();

      switch (result)
      {
      case clsBankClient::enSaveResults::svSuceeded:
        cout << "Succeeded!" << endl;
        _PrintClientInfo(client);
        break;

      case clsBankClient::enSaveResults::svFailedAccountInUse:
        cout << "Account Already in use!" << endl;
        break;

      default:
        break;
      }
    }

};