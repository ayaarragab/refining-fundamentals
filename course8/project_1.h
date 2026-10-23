#pragma once
#include "client_data_funcs.h"
#include "user_funcs.h"
#include <cstdlib>

namespace project1
{
  struct stSystemSession
  {
    user_namspc::stUser user;
  };
  
  enum enOptions
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

  enum enTranOptions
  {
    Deposit = 1,
    Withdraw = 2,
    tMainMenu = 3
  };
  void start_session(stSystemSession &session);
  void show_login(stSystemSession &session);
  bool check_permissions(stSystemSession &session, user_namspc::enPermissions requiredPermissions) {
      bool allowed = user_namspc::check_access((int)session.user.permissions, requiredPermissions);
      if (!allowed)
      {
        system("clear");
        cout << "Access Denied" << endl;
        cout << "You're unauthorized to access this section" << endl;
        cout << "Only authorized users allowed." << endl;
        return false;
      }
      return true;
    }

  void start_program(enOptions option, stSystemSession &session);
  void show_main_menu();

  void start_session(stSystemSession &session) {
    show_main_menu();
    enOptions option = (project1::enOptions)input_funcs::readNum("Enter option 1-7, 8 for main menu ,or -1 for ending the program:");
    while (option != -1)
    {
      start_program(option, session);
      option = (project1::enOptions)input_funcs::readNum("Enter option 1-7, 8 for main menu ,or -1 for ending the program:");
      show_main_menu();
  }
  }

  void login_header() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Login Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  void show_login(stSystemSession &session) {
    login_header();
    bool enter_again = true;
    while (enter_again)
    {
      user_namspc::stUser user = user_namspc::login();
      if (user.username != "")
      {
        session.user = user;
        cout << "You've logged in successfully!\n";
        system("clear");
        start_session(session);
      }
      cout << "There're no users with this name!\n";
      enter_again = input_funcs::wants_to_enter();
    }
    
  }

  void show_main_menu()
  {
    cout << "==============================================================\n";
    cout << "\t\t\tMain Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] Show Client List\t\t\t\n";
    cout << "\t\t\t[2] Add Client\t\t\t\n";
    cout << "\t\t\t[3] Delete Client\t\t\t\n";
    cout << "\t\t\t[4] Update Client\t\t\t\n";
    cout << "\t\t\t[5] Find Client\t\t\t\n";
    cout << "\t\t\t[6] Transactions\t\t\t\n";
    cout << "\t\t\t[7] Manage Users\t\t\t\n";
    cout << "\t\t\t[8] Exit\t\t\t\n";
    cout << "==============================================================\n";
  }

  void show_transactions_menu()
  {
    cout << "==============================================================\n";
    cout << "\t\t\tTransactions Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] Deposit\t\t\t\n";
    cout << "\t\t\t[2] Withdraw\t\t\t\n";
    cout << "\t\t\t[2] Back to Main Menue\t\t\t\n";
    cout << "==============================================================\n";
  }

  void show_manage_users_menu()
  {
    cout << "==============================================================\n";
    cout << "\t\t\tManage Users Menu Screen\t\t\t\n";
    cout << "\t\t\t[1] List Users\t\t\t\n";
    cout << "\t\t\t[2] Add Users\t\t\t\n";
    cout << "\t\t\t[3] Delete Users\t\t\t\n";
    cout << "\t\t\t[4] Update Users\t\t\t\n";
    cout << "\t\t\t[5] Find Users\t\t\t\n";
    cout << "\t\t\t[6] Back to Main Menue\t\t\t\n";
    cout << "==============================================================\n";
  }

  void show_add_user()
  {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Add New User Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    user_namspc::stUser user;
    bool add_again = true;
    while (add_again)
    {
      user_namspc::add_user(user);
      cout << "Do you want to add another user ? \n";
      add_again = input_funcs::wants_to_enter();
    }
    system("clear");
    show_manage_users_menu();
  }

  void update_user_header() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Update User Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  void delete_user_header() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Delete User Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  void find_user_header() {
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Find User Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
  }

  void show_update_user() {
    update_user_header();
    bool add_again = true;
    while (add_again)
    {
      string username = input_funcs::readString("Enter username");
      user_namspc::update_user_in_file(username);
      cout << "Do you want to update another user ? \n";
      add_again = input_funcs::wants_to_enter();
    }
    system("clear");
    show_manage_users_menu();
  }

  void show_delete_user() {
    delete_user_header();
    bool add_again = true;
    while (add_again)
    {
      string username = input_funcs::readString("Enter username");
      user_namspc::delete_user(username, true);
      cout << "Do you want to delete another user ? \n";
      add_again = input_funcs::wants_to_enter();
    }
    system("clear");
    show_manage_users_menu();
  }

  void show_find_user() {
    find_user_header();
    bool add_again = true;
    while (add_again)
    {
      string username = input_funcs::readString("Enter username");
      user_namspc::stUser user = user_namspc::find_user(username);
      if (user.username != "")
        user_namspc::print_user(user);
      
      cout << "Do you want to find another user ? \n";
      add_again = input_funcs::wants_to_enter();
    }
    system("clear");
    show_manage_users_menu();
  }

  void start_manage_users(user_namspc::enManageUsersOp option)
  {
    switch (option)
    {
    case user_namspc::ListUsers:
      system("clear");
      break;
    case user_namspc::AddUsers:
      system("clear");
      show_add_user();
      break;
    case user_namspc::DeleteUsers:
      system("clear");
      show_delete_user();
      break;
    case user_namspc::UpdateUsers:
      system("clear");
      show_update_user();
      break;
    case user_namspc::FindUsers:
      system("clear");
      show_find_user();
      break;
    case user_namspc::mMainMenu:
      system("clear");
      show_main_menu();
      break;
    default:
      break;
    }
  }

  void manage_users_start(stSystemSession &session)
  {
    if (!check_permissions(session, user_namspc::ManageUsers))
      return;
    show_manage_users_menu();
    user_namspc::enManageUsersOp option = (user_namspc::enManageUsersOp)input_funcs::readNum("Enter option 1-5, 6 for main menu ,or -1 for ending the program:");
    while (option != -1)
    {
      start_manage_users(option);
      option = (user_namspc::enManageUsersOp)input_funcs::readNum("Enter option 1-5, 6 for main menu ,or -1 for ending the program:");
      show_manage_users_menu();
    }
    system("clear");
    show_main_menu();
  }

  void show_clients_list(stSystemSession &session)
  {
    if (!check_permissions(session, user_namspc::ClientList))
      return;
    
    client_data_funcs::display_clients();
  }

  void show_add_client(stSystemSession &session)
  {
    if (!check_permissions(session, user_namspc::AddClient))
      return;
    
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Add New Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    client_data_funcs::save_clients_data_to_file();
    cout << "Client data entered successfully\n";
  }

  void show_delete_client(stSystemSession &session)
  {
    if (!check_permissions(session, user_namspc::DeleteClient))
      return;
    
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Delete Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    string acc_num = input_funcs::readString("Enter acc number:");
    client_data_funcs::delete_with_acc_num(acc_num);
    cout << "Client deleted successfully\n";
  }

  void show_update_client(stSystemSession &session)
  {
    if (!check_permissions(session, user_namspc::UpdateClient))
      return;
    
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Update Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    string acc_num = input_funcs::readString("Enter acc number:");
    client_data_funcs::update_with_acc_num(acc_num);
    cout << "Client updated successfully\n";
  }

  void find_client()
  {
    client_data_funcs::stClientData client;
    client_data_funcs::print_dashs();
    cout << client_data_funcs::tabs_(3) << " Find Client Screen " << client_data_funcs::tabs_(3) << endl;
    client_data_funcs::print_dashs();
    string acc_num = input_funcs::readString("Enter acc number:");
    client_data_funcs::find_with_acc_num(acc_num);
  }

  void exit_()
  {
    cout << "Exiting ..." << endl;
    exit(0);
  }

  void start_transactions(enTranOptions option)
  {
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

  void transactions_start(stSystemSession &session)
  {
    if (!check_permissions(session, user_namspc::Transactions))
      return;
    
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

  void start_program(enOptions option, stSystemSession &session)
  {
    switch (option)
    {
    case ClientList:
      system("clear");
      show_clients_list(session);
      break;
    case AddClient:
      system("clear");
      show_add_client(session);
      break;
    case DeleteClient:
      system("clear");
      show_delete_client(session);
      break;
    case UpdateClient:
      system("clear");
      show_update_client(session);
      break;
    case FindClient:
      system("clear");
      show_update_client(session);
      break;
    case Transactions:
      system("clear");
      transactions_start(session);
      break;
    case ManageUsers:
      system("clear");
      manage_users_start(session);
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
