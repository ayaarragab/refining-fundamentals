#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
  private:
    static void _print_header_balances(short vec_length)
    {
        cout << "\t\t\t  Client List (" << vec_length << ") Client(s).\n";
        cout << "-------------------------------------------------------------------------\n";
        
        cout << "| " << left << setw(15) << "Account Number"
            << "| " << left << setw(20) << "Client Name"
            << "| " << left << setw(12) << "Balance"
            << "\n";
            
        cout << "-------------------------------------------------------------------------\n";
    }

    static void _ListBalances()
    {
        vector<clsBankClient> clients = clsBankClient::ClientList();
        _print_header_balances(clients.size());

        for (clsBankClient &c : clients)
        {
            cout << "| " << left << setw(15) << c.GetAccountNumber()
                << "| " << left << setw(20) << (c.GetFirstName() + " " + c.GetLastName())
                << "| " << left << setw(12) << c.getAccountBalance()
                << endl;
        }
        
        cout << "-------------------------------------------------------------------------\n";
        double summation = clsBankClient::GetSumOfBalances();
        cout << left << setw(10) << "Client Total Balances (" << summation << ") Dollar(s)." << endl;
        cout << left << setw(10) << clsUtil::numberToWords(int(summation))<< endl;
        cout << "-------------------------------------------------------------------------\n";
        cout << endl;
    }
public:
  static void ShowTotalBalances()
  {
    _ListBalances();
  }
};
