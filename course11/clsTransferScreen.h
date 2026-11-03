#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInput.h"
#include "clsInputValidate.h"

class clsTransferScreen: protected clsScreen {
  private:
    static void _PrintClientInfo(clsBankClient client) {
      cout << "Full Name: " << client.GetFirstName() + " " + client.GetLastName() << endl;
      cout << "Account Number: " << client.GetAccountNumber() << endl;
      cout << "Account Balance: " << client.getAccountBalance() << endl;
    }
public:
    static void ShowTransferScreen() {
      string Sender = clsInput::readString("Enter Sender Account Number");
      string Reciever = clsInput::readString("Enter Reciever Account Number");
      double Quantity = clsInputValidate::ReadDblNumber("Invalid number");

      bool TransferDone = clsBankClient::Transfer(Sender, Reciever, Quantity);
      
      if (TransferDone)
        cout << "Transfer is done successfully" << endl;
      else
        cout << "One of the accounts not found" << endl;
    }
};