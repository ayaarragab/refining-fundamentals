#pragma once
#include "clsScreen.h"
#include <iomanip>

class clsTransactionsMenuScreen: clsScreen
{
private:
  enum enTranOptions
  {
    Deposit = 1,
    Withdraw = 2,
    tMainMenu = 3
  };

  static void _ShowDepositScreen() {}

  static void _ShowNormalWithdrawScreen() {}

  static void _ShowQuickWithdrawScreen() {}

  static void _ShowListBalancesScreen() {}

  static void _PerformTransationsMenuOtions(enTranOptions option)
  {
    switch (option)
    {
    case Deposit:
      system("clear");
      break;
    case Withdraw:
      system("clear");
      break;
    case tMainMenu:
      system("clear");
      break;
    default:
      break;
    }
  }

public:
  static void ShowTransactionMenuScreen() {
    _DrawScreenHeader("Transactions Menu Screen");
    cout << setw(37) << left << "" << "==============================================================\n";
    cout << setw(37) << left << "" << "\t\t\tTransactions Menu Screen\t\t\t\n";
    cout << setw(37) << left << "" <<  "\t\t\t[1] Deposit\t\t\t\n";
    cout << setw(37) << left << "" <<  "\t\t\t[2] Withdraw\t\t\t\n";
    cout << setw(37) << left << "" <<  "\t\t\t[2] Back to Main Menue\t\t\t\n";
    cout << setw(37) << left << "" <<  "==============================================================\n";
  }
};
