#pragma once
#include <iomanip>
#include <limits>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"

class clsMainScreen : protected clsScreen
{
private:
  enum enMainMenuOptions
  {
    ClientList = 1,
    AddClient = 2,
    DeleteClient = 3,
    UpdateClient = 4,
    FindClient = 5,
    Transactions = 6,
    ManageUsers = 7,
    Exit = 8,
    MainMenu = 9
  };
  static enMainMenuOptions _ReadMainMenuOption()
  {
    enMainMenuOptions option = (enMainMenuOptions)clsInputValidate::ReadIntNumberBetween(1, 9, "This is an invalid number");
    return option;
  }


  static void _GoBackToMainMenue()
  {
      cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
      
      ShowMainMenue();
  }

  static void _ShowAllClientsScreen()
  {
     clsClientListScreen::ShowClientList();
  }

  static void _ShowAddNewClientsScreen()
  {
    clsAddNewClientScreen::AddClient();
  }

  static void _ShowDeleteClientScreen()
  {
    clsDeleteClientScreen::DeleteClient();
  }

  static void _ShowUpdateClientScreen()
  {
    cout << "\nUpdate Client Screen Will be here...\n";
  }

  static void _ShowFindClientScreen()
  {
    cout << "\nFind Client Screen Will be here...\n";
  }

  static void _ShowTransactionsMenue()
  {
    cout << "\nTransactions Menue Will be here...\n";
  }

  static void _ShowManageUsersMenue()
  {
    cout << "\nUsers Menue Will be here...\n";
  }

  static void _ShowEndScreen()
  {
    cout << "\nEnd Screen Will be here...\n";
  }
  static void _PerformMainMenuOperations(enMainMenuOptions option)
  {
    switch (option)
    {
    case ClientList:
      system("clear");
      _ShowAllClientsScreen();
      _GoBackToMainMenue();
      break;
    case AddClient:
      system("clear");
      _ShowAddNewClientsScreen();
      _GoBackToMainMenue();
      break;
    case DeleteClient:
      system("clear");
      _ShowDeleteClientScreen();
      _GoBackToMainMenue();
      break;
    case UpdateClient:
      system("clear");
      _ShowUpdateClientScreen();
      _GoBackToMainMenue();
      break;
    case FindClient:
      system("clear");
      _ShowFindClientScreen();
      _GoBackToMainMenue();
      break;
    case Transactions:
      system("clear");
      _ShowTransactionsMenue();
      _GoBackToMainMenue();
      break;
    case ManageUsers:
      system("clear");
      _ShowManageUsersMenue();
      _GoBackToMainMenue();
      break;
    case Exit:
      system("clear");
      _ShowEndScreen();
      // Login
      break;
    case MainMenu:
      system("clear");
      ShowMainMenue();
      break;
    default:
      break;
    };
  }

public:
  static void ShowMainMenue()
  {

    system("clear");
    _DrawScreenHeader("\t\tMain Screen");

    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
    cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
    cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
    cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
    cout << setw(37) << left << "" << "\t[5] Find Client.\n";
    cout << setw(37) << left << "" << "\t[6] Transactions.\n";
    cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
    cout << setw(37) << left << "" << "\t[8] Logout.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    _PerformMainMenuOperations(_ReadMainMenuOption());
  }
};