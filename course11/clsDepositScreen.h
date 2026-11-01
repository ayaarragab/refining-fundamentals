#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositClientScreen : protected clsScreen
{
private:
  static clsBankClient _GetClient()
  {
    clsBankClient client = clsBankClient::Find(clsInput::readString("Enter an account number"));
    while (client.IsEmpty())
    {
      cout << "There're no clients with this account number" << endl;
      client = clsBankClient::Find(clsInput::readString("Enter an account number"));
    }
    return client;
  }

  static void _DepositClient(clsBankClient &client, double number) {
    client.Deposit(number);
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
  static void ShowDepositClient()
  {
    clsBankClient client = _GetClient();
    double quantity = clsInputValidate::ReadDblNumber("Invalid Number");
    _DepositClient(client, quantity);
    _PrintClientInfo(client);
}
};
