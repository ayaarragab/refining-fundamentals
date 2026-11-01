#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"

class clsTransactionsMenuScreen : clsScreen
{
private:
  enum enTranOptions
  {
    Deposit = 1,
    Withdraw = 2,
    tMainMenu = 3
  };

  static void _ShowDepositScreen() {}

  static void _ShowWithdrawScreen() {}

  static void _ShowListBalancesScreen() {}

  static void _GoBackToTransactionsMenue()
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
      _GoBackToTransactionsMenue();
      break;
    case Withdraw:
      system("clear");
      _ShowWithdrawScreen();
      _GoBackToTransactionsMenue();
      break;
    case tMainMenu:
      system("clear");
      clsMainScreen::ShowMainMenue();
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
