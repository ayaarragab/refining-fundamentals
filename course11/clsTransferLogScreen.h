#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:
  static void _print_dashs()
  {
    cout << setw(20) << left << "———————————————————————————————————————————————————————————————————————————————————\n";
    ;
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
      cout << "\n" << setw(25) << "" << "Users List (" << vec_length << ") User(s).\n";
      _print_dashs();

      cout << "| " << left << setw(19) << "DateTime"
          << "| " << left << setw(19) << "Sender"
          << "| " << left << setw(19) << "Reciever"
          << "| " << left << setw(19) << "Sender Old Balance"
          << "| " << left << setw(19) << "Sender New Balance"
          << "| " << left << setw(19) << "Reciever Balance"
          << "| " << left << setw(14) << "User"
          << endl;

      _print_dashs();
  }
  static void _PrintLine(clsBankClient::stTransferLogInfo transfer)
  {
    cout <<  "| " << left << setw(19) << transfer.DateTime
         <<  "| " << left << setw(19) << transfer.SenderAccNum
         <<  "| " << left << setw(19) << transfer.RecieverAccNum
         <<  "| " << left << setw(14) << transfer.SenderOldBalance
         <<  "| " << left << setw(14) << transfer.SenderNewBalance
         <<  "| " << left << setw(14) << transfer.RecieverBalance
         <<  "| " << left << setw(14) << transfer.Username
         << "\n";
  }

public:
  static void ShowTransferLogScreen() {
    if (!clsUser::CheckPermissions((clsUser::enPermissions)CurrentUser.GetPermissions(), clsUser::enPermissions::LoginRegister))
    {
      cout << "Access Denied" << endl;
      return;
    }
    _DrawScreenHeader("Transfer Log Screen");
    vector<clsBankClient::stTransferLogInfo> transfers = clsBankClient::GetTransfersInfo();
    _print_header(transfers.size());
    for (clsBankClient::stTransferLogInfo &t: transfers)
      _PrintLine(t);
  }
};