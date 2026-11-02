#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen .h"
#include "clsInputValidate.h"
#include "clsTotalBalancesScreen.h"

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

  static enTranOptions _ReadTransactionMenuOption()
  {
    enTranOptions option = (enTranOptions)clsInputValidate::ReadIntNumberBetween(1, 9, "This is an invalid number");
    return option;
  }

  static void _ShowDepositScreen()
  {
    clsDepositClientScreen::ShowDepositClient();
  }

  static void _ShowWithdrawScreen()
  {
    clsWithdrawClientScreen::ShowWithdrawClient();
  }

  static void _ShowListBalancesScreen()
  {
    clsTotalBalancesScreen::ShowTotalBalances();
  }

  static void _GoBackToTransactionsMenu()
  {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");
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
    {
    }
    default:
      break;
    }
  }

public:
  static void ShowTransactionMenuScreen()
  {
    if (!clsUser::CheckPermissions((clsUser::enPermissions)CurrentUser.GetPermissions(), clsUser::enPermissions::Transactions))
    {
      cout << "Access Denied" << endl;
      return;
    }
    _DrawScreenHeader("Transactions Menu Screen");
    cout << setw(37) << left << "" << "==============================================================\n";
    cout << setw(37) << left << "" << "\t\t\tTransactions Menu Screen\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[1] Deposit\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[2] Withdraw\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[3] Total Balances\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[4] Back to Main Menue\t\t\t\n";
    cout << setw(37) << left << "" << "==============================================================\n";
    _PerformTransationsMenuOtions(_ReadTransactionMenuOption());
  }
};
