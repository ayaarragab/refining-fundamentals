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
    Exit=6,
    MainMenue=7
  };

  void show_main_menu() {
    cout << "==============================================================\n";
    cout << "\t\t\tMain Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] Show Client List\t\t\t\n";
    cout << "\t\t\t[2] Add Client\t\t\t\n";
    cout << "\t\t\t[2] Delete Client\t\t\t\n";
    cout << "\t\t\t[3] Update Client\t\t\t\n";
    cout << "\t\t\t[4] Find Client\t\t\t\n";
    cout << "\t\t\t[5] Exit\t\t\t\n";
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
    case Exit:
      system("clear");
      exit_();
      break;
    case MainMenue:
      system("clear");
      show_main_menu();
      break;
    default:
      break;
    }
  }
} // namespace project1
