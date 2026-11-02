#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsListUsersScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
  enum enManageUsersOp {
    ListUsers = 1,
    AddUsers = 2,
    DeleteUsers = 3,
    UpdateUsers = 4,
    FindUsers = 5,
    mMainMenu = 6
  };

  static enManageUsersOp _ReadManageUsersMenuOption()
  {
    enManageUsersOp option = (enManageUsersOp)clsInputValidate::ReadIntNumberBetween(1, 9, "This is an invalid number");
    return option;
  }

  static void _ShowListUsersScreen() {
    clsListUsers::ShowUserList();
  }

  static void _ShowAddUsersScreen() {
  }

  static void _ShowDeleteUsersScreen() {
  }

  static void _ShowUpdateUsersScreen() {
  }

  static void _ShowFindUsersScreen() {
  }

  static void _GoBackToManageUsersMenu()
  {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");
    ShowManageUsersMenuScreen();
  }

  static void _PerformManageUsersMenuOtions(enManageUsersOp option)
  {
    switch (option)
    {
    case ListUsers:
      system("clear");
      _ShowListUsersScreen();
      _GoBackToManageUsersMenu();
      break;
    case AddUsers:
      system("clear");
      _ShowAddUsersScreen();
      _GoBackToManageUsersMenu();
      break;
    case DeleteUsers:
      system("clear");
      _ShowDeleteUsersScreen();
      _GoBackToManageUsersMenu();
      break;
    case UpdateUsers:
      system("clear");
      _ShowUpdateUsersScreen();
      _GoBackToManageUsersMenu();
      break;
    case mMainMenu:
      system("clear");
      break;
    default:
      break;
    }
  }

public:
  static void ShowManageUsersMenuScreen()
  {
    _DrawScreenHeader("Manage Users Menu Screen");
    cout << setw(37) << left << "" << "==============================================================\n";
    cout << setw(37) << left << "" << "\t\t\tManage Users Menu Screen\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[1] List Users\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[2] Add Users\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[3] Delete Users\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[4] Update Users\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[5] Find Users\t\t\t\n";
    cout << setw(37) << left << "" << "\t\t\t[6] Back to Main Menue\t\t\t\n";
    cout << setw(37) << left << "" << "==============================================================\n";
    _PerformManageUsersMenuOtions(_ReadManageUsersMenuOption());
  }
};
