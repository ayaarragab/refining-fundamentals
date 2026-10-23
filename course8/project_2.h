#pragma once
#include "client_data_funcs.h"
#include <cstdlib>
#include "user_funcs.h"

namespace project2
{

  // enums

  enum enOption {
    pQuickWithdraw=1,
    pNormalWithdraw=2,
    pDeposit=3,
    pCheckBalance=4,
    pLogout=5
  };

  // screens
  void print_login_screen() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Login Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  // show menus
  void show_main_menu()
  {
    cout << "==============================================================\n";
    cout << "\t\t\tMain Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] Quick Withdraw\t\t\t\n";
    cout << "\t\t\t[2] Normal Withdraw\t\t\t\n";
    cout << "\t\t\t[3] Deposit\t\t\t\n";
    cout << "\t\t\t[4] Check Balance\t\t\t\n";
    cout << "\t\t\t[5] Logout\t\t\t\n";
    cout << "==============================================================\n";
  }

  // forward to show action based on user choice from menu
  void forward_to_show_action(enOption option) {
    switch (option)
    {
    case pQuickWithdraw:
      system("clear");
      // show_quick_withdraw
      break;
    case pNormalWithdraw:
      system("clear");
      // show_normal_withdraw
      break;
    case pDeposit:
      system("clear");
      // show_deposit
      break;
    case pCheckBalance:
      system("clear");
      // show_check_balance
      break;
    case pLogout:
      system("clear");
      // show_logout
      break;
    default:
      break;
    }
  }
  
  // start program

  void start_program() {
    show_main_menu();
    enOption option;
    int choice;
    do
    {
      choice = input_funcs::readNum("Choose option from 1-4, 5 for logout, -1 for ending the program");
      option = (enOption)choice;
      forward_to_show_action(option);
      system("clear");
    } while (choice != -1);
  }

  // actions 
  void login() {
    string acc_num;
    string pin;
    bool found;
    do
    {
      acc_num = input_funcs::readString("Enter account number");
      pin = input_funcs::readString("Enter pin");
      found = client_data_funcs::find_with_acc_num(acc_num);
      if (!found)
        cout << "Invalid credintials\n";
    } while (!found);
  }

  // show actions
  void show_login() {
    print_login_screen();
    login();
    system("clear");
    start_program();
  }
} // namespace project2
