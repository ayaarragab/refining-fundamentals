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

  void print_quick_withdraw_screen() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Quick Withdraw Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    for (short i = 0; i < 10; i++)
      cout << setw(15) << "[" + to_string((i + 1) * 10) + "]. $" + to_string((i + 1) * 10) << setw(15) << "[" + to_string((i + 1) * 100) + "]. $" + to_string((i + 1) * 100) << setw(15) << endl;
  }

  void print_normal_withdraw_screen() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Normal Withdraw Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  void print_check_balance_screen() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Check Balance Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  void print_deposit_screen() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Deposit Screen " << client_data_funcs::tabs_(3) << endl;
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
  
  // start program
  void forward_to_show_action(enOption option, client_data_funcs::stClientData &currentclient);
  void start_program(client_data_funcs::stClientData &currentclient) {
    show_main_menu();
    enOption option;
    int choice;
    do
    {
      choice = input_funcs::readNum("Choose option from 1-4, 5 for logout, -1 for ending the program");
      option = (enOption)choice;
      forward_to_show_action(option, currentclient);
    } while (choice != -1);
  }

  // actions 
  void login(client_data_funcs::stClientData &currentclient) {
    string acc_num;
    string pin;
    bool found;
    do
    {
      client_data_funcs::stClientData c;
      acc_num = input_funcs::readString("Enter account number");
      pin = input_funcs::readString("Enter pin");
      found = client_data_funcs::find_with_acc_num(acc_num, c);
      currentclient = c;
      if (!found)
        cout << "Invalid credintials\n";
    } while (!found);
  }

  void quick_withdraw(client_data_funcs::stClientData &currentclient) {
    int amount = input_funcs::readNum("Choose amount from the above");
    if (amount > currentclient.balance)
    {
      cout << "You can't withdraw this amount!\n";
      return;
    }
    client_data_funcs::update_balance(currentclient.account_number, -amount);
    cout << "You've withdrawn $" + to_string(amount) + " successfully" << endl;
  }

  void normal_withdraw(client_data_funcs::stClientData &currentclient) {
    int amount = input_funcs::readNum("Choose amount that is multiple of 5");
    if (amount > currentclient.balance)
    {
      cout << "You can't withdraw this amount!\n";
      return;
    }
    
    client_data_funcs::update_balance(currentclient.account_number, -amount);
    cout << "You've withdrawn $" + to_string(amount) + " successfully" << endl;
  }

  void check_balance(client_data_funcs::stClientData &currentclient) {
    client_data_funcs::get_balance(currentclient.account_number);
  }

  void deposit(client_data_funcs::stClientData &currentclient) {
    int amount = input_funcs::readNum("Choose amount to deposit");
    client_data_funcs::update_balance(currentclient.account_number, amount);
    cout << "You've deposit $" + to_string(amount) + " successfully" << endl;
  }

  // show actions
  void show_login(client_data_funcs::stClientData &currentclient) {
    print_login_screen();
    login(currentclient);
    system("clear");
    start_program(currentclient);
  }

  void show_quick_withdraw(client_data_funcs::stClientData &currentclient) {
    print_quick_withdraw_screen();
    quick_withdraw(currentclient);
  }

  void show_normal_withdraw(client_data_funcs::stClientData &currentclient) {
    print_normal_withdraw_screen();
    normal_withdraw(currentclient);
  }

  void show_check_balance(client_data_funcs::stClientData &currentclient) {
    print_check_balance_screen();
    check_balance(currentclient);
  }

  void show_deposit(client_data_funcs::stClientData &currentclient) {
    print_deposit_screen();
    deposit(currentclient);
  }
  
  // forward to show action based on user choice from menu
  void forward_to_show_action(enOption option, client_data_funcs::stClientData &currentclient) {
    switch (option)
    {
    case pQuickWithdraw:
      system("clear");
      show_quick_withdraw(currentclient);
      break;
    case pNormalWithdraw:
      system("clear");
      show_normal_withdraw(currentclient);
      break;
    case pDeposit:
      system("clear");
      show_deposit(currentclient);
      break;
    case pCheckBalance:
      system("clear");
      show_check_balance(currentclient);
      break;
    case pLogout:
      system("clear");
      show_login(currentclient);
      break;
    default:
      break;
    }
  }
} // namespace project2
