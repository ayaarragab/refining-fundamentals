#pragma once
#include <iomanip>
#include "clsScreen.h"

class clsTransactionsMenuScreen : protected clsScreen
{
private:
  enum enTranOptions
  {
    Deposit = 1,
    Withdraw = 2,
    TotalBalances = 3,
    tMainMenu = 4
  };

  static void _ShowDepositScreen() {}

  static void _ShowWithdrawScreen() {}

  static void _ShowListBalancesScreen() {}

  static void _GoBackToTransactionsMenu()
  {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    ShowTransactionMenuScreen();
  }

  static void _PerformTransationsMenuOtions(enTranOptions option)
  {
    switch (option)
    {
    case Deposit:
      system("clear");
      _ShowDepositScreen();
      _GoBackToTransactionsMenu();
      break;
    case Withdraw:
      system("clear");
      _ShowWithdrawScreen();
      _GoBackToTransactionsMenu();
      break;
    case TotalBalances:
      system("clear");
      _ShowListBalancesScreen();
      _GoBackToTransactionsMenu();
      break;
    case tMainMenu:
      system("clear");
      break;
    default:
      break;
    }
  }

public:
  static void ShowTransactionMenuScreen()
  {
    _DrawScreenHeader("Transactions Menu Screen");
    cout << setw(37) << left << "" << "==============================================================\n";
    cout << setw(37) << left << "" << "\t\t\tTransactions Menu Screen\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[1] Deposit\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[2] Withdraw\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[2] Back to Main Menue\t\t\t\n";
    cout << setw(37) << left << "" << "==============================================================\n";
  }
};
