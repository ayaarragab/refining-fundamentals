#pragma once
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsClientListScreen: protected clsScreen {
  private:
    static void _print_dashs()
    {
      cout << setw(20) << left << "" << "—————————————————————————————————————————————————————————————————————————————————————\n";;
    }

    static string _tabs(int num)
    {
      string t = "";
      for (short i = 0; i < num; i++)
        t.append("\t");
      return t;
    }

    static void _print_header(short vec_length)
    {
        cout << setw(37) << left << "" << "  Client List (" << vec_length << ") Client(s).\n";
        _print_dashs();
        
        cout << setw(20) << left  << "" << "| " << left << setw(15) << "Account Number"
            << "| " << left << setw(10) << "Pin Code"
            << "| " << left << setw(20) << "Client Name"
            << "| " << left << setw(14) << "Phone"
            << "| " << left << setw(12) << "Balance"
            << "\n";
            
        _print_dashs();
    }
    
    static void _ListClients()
    {
      if (!clsUser::CheckPermissions((clsUser::enPermissions)CurrentUser.GetPermissions(), clsUser::enPermissions::ClientList))
      {
        cout << "Access Denied" << endl;
        return;
      }
      vector<clsBankClient> clients = clsBankClient::ClientList();
      _print_header(clients.size());

      for (clsBankClient &c : clients)
      {
          cout << setw(20) << left << "" << "| " << left << setw(15) << c.GetAccountNumber()
              << "| " << left << setw(10) << c.GetPinCode()
              << "| " << left << setw(20) << (c.GetFirstName() + " " + c.GetLastName())
              << "| " << left << setw(14) << c.GetPhone()
              << "| " << left << setw(12) << c.getAccountBalance()
              << endl;
      }
      
      _print_dashs();
  } 


  public:
    static void ShowClientList() {
      _DrawScreenHeader("Show Client List Screen");
      _ListClients();
    }
};