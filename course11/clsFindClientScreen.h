#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen: protected clsScreen
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
    static void ShowFindClient() {
      _DrawScreenHeader("Find Client Screen");
      clsBankClient client = clsBankClient::Find(clsInput::readString("Enter Account Number"));
      if (client.GetAccountNumber() == "")
        cout << "No clients found with this Account Number" << endl;
      else {
        _PrintClientInfo(client);
      }
    }
};