#include "client_data_funcs.h"

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
    // here will be a function that displays the clients (i'll implement it)
  }
} // namespace project1
