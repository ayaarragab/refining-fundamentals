#include "client_data_funcs.h"
#include <cstdlib>

namespace project1
{
  enum enOptions {
    ClientList=1,
    AddClient=2,
    DeleteClient=3,
    UpdateClient=4,
    FindClient=5,
    Transactions=6,
    Exit=7,
    MainMenu=8
  };

  enum enTranOptions {
    Deposit=1,
    Withdraw=2,
    tMainMenu=3
  };

  void show_main_menu() {
    cout << "==============================================================\n";
    cout << "\t\t\tMain Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] Show Client List\t\t\t\n";
    cout << "\t\t\t[2] Add Client\t\t\t\n";
    cout << "\t\t\t[3] Delete Client\t\t\t\n";
    cout << "\t\t\t[4] Update Client\t\t\t\n";
    cout << "\t\t\t[5] Find Client\t\t\t\n";
    cout << "\t\t\t[6] Transactions\t\t\t\n";
    cout << "\t\t\t[7] Exit\t\t\t\n";
    cout << "==============================================================\n";
  }

  void show_transactions_menu() {
    cout << "==============================================================\n";
    cout << "\t\t\tTransactions Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] Deposit\t\t\t\n";
    cout << "\t\t\t[2] Withdraw\t\t\t\n";
    cout << "\t\t\t[2] Back to Main Menue\t\t\t\n";
    cout << "==============================================================\n";
  }
  
  void show_clients_list() {
    client_data_funcs::display_clients();
  }
  
  void show_add_client() {
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Add New Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    client_data_funcs::save_clients_data_to_file();
    cout << "Client data entered successfully\n";
  }

  void show_delete_client() {
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Delete Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    string acc_num = input_funcs::readString("Enter acc number:");
    client_data_funcs::delete_with_acc_num(acc_num);
    cout << "Client deleted successfully\n";
  }

  void show_update_client() {
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Update Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    string acc_num = input_funcs::readString("Enter acc number:");
    client_data_funcs::update_with_acc_num(acc_num);
    cout << "Client updated successfully\n";
  }

  void find_client() {
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Find Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    string acc_num = input_funcs::readString("Enter acc number:");
    client_data_funcs::find_with_acc_num(acc_num);
  }

  void exit_() {
    cout << "Exiting ..." << endl;
    exit(0);
  }


    void start_transactions(enTranOptions option) {
    switch (option)
    {
    case Deposit:
      system("clear");
      client_data_funcs::deposit();
      break;
    case Withdraw:
      system("clear");
      client_data_funcs::withdraw();
      break;
    case tMainMenu:
      system("clear");
      show_main_menu();
      break;
    default:
      break;
    }
  }

  void transactions_start() {
    show_transactions_menu();
    enTranOptions option = (enTranOptions)input_funcs::readNum("Enter option 1-2, 3 for main menu ,or -1 for ending the program:");
    while (option != -1)
    {
      start_transactions(option);
      option = (enTranOptions)input_funcs::readNum("Enter option 1-2, 3 for main menu ,or -1 for ending the program:");
      show_transactions_menu();
    }
    show_main_menu();
  }

  void start_program(enOptions option) {
    switch (option)
    {
    case ClientList:
      system("clear");
      show_clients_list();
      break;
    case AddClient:
      system("clear");
      show_add_client();
      break;
    case DeleteClient:
      system("clear");
      show_delete_client();
      break;
    case UpdateClient:
      system("clear");
      show_update_client();
      break;
    case FindClient:
      system("clear");
      show_update_client();
      break;
    case Transactions:
      system("clear");
      transactions_start();
      break;
    case Exit:
      system("clear");
      exit_();
      break;
    case MainMenu:
      system("clear");
      show_main_menu();
      break;
    default:
      break;
    };
  }
} // namespace project1
