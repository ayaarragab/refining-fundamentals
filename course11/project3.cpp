#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsInput.h"
#include "clsUtil.h"

using namespace std;

// void print_header_balances(short vec_length)
// {
//     cout << tabs_(3) << "  Client List (" << vec_length << ") Client(s).\n";
//     print_dashs();
    
//     cout << "| " << left << setw(15) << "Account Number"
//          << "| " << left << setw(20) << "Client Name"
//          << "| " << left << setw(12) << "Balance"
//          << "\n";
         
//     print_dashs();
// }

// void print_footer()
// {
//   print_dashs();
// }





// void ListBalances()
// {
//     vector<clsBankClient> clients = clsBankClient::ClientList();
//     print_header(clients.size());

//     for (clsBankClient &c : clients)
//     {
//         cout << "| " << left << setw(15) << c.GetAccountNumber()
//              << "| " << left << setw(20) << (c.GetFirstName() + " " + c.GetLastName())
//              << "| " << left << setw(12) << c.getAccountBalance()
//              << endl;
//     }
    
//     print_dashs();
//     double summation = clsBankClient::GetSumOfBalances();
//     cout << left << setw(10) << "Client Total Balances (" << summation << ") Dollar(s)." << endl;
//     cout << left << setw(10) << clsUtil::numberToWords(int(summation))<< endl;
//     print_dashs();
//     cout << endl;
// }

int main()
{
  clsMainScreen::ShowMainMenue();
  return 0;
}