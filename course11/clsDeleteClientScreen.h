#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsDeleteClientScreen: protected clsScreen
{
  private:
    static void _PrintClientInfo(clsBankClient client) {
      cout << "Account Name: " << client.GetFirstName() + " " + client.GetLastName() << endl;
      cout << "Account Phone: " << client.GetPhone() << endl;
      cout << "Account Email: " << client.GetEmail() << endl;
      cout << "Account Number: " << client.GetAccountNumber() << endl;
      cout << "Account Balance: " << client.getAccountBalance() << endl;
      cout << "Account Pin Code: " << client.GetPinCode() << endl;
    }
  
  public:

    static void DeleteClient()
    {
      string AccountNumber = clsInput::readString("Enter account Number");

      clsBankClient client = clsBankClient::Find(AccountNumber);

      while (client.IsEmpty())
      {
        cout << "No Client Exists with this Account Number" << endl;
        AccountNumber = clsInput::readString("Enter account Number");
        client = clsBankClient::Find(AccountNumber);
      }
      _PrintClientInfo(client);
      bool deleted = client.Delete();

      if (deleted)
        cout << "Client Deleted Successfully" << endl;
      else
        cout << "No Client is deleted" << endl;
    }

};