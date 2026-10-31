#include "clsBankClient.h"
#include "clsInput.h"
#include "clsUtil.h"
#include <iostream>
#include <iomanip>
using namespace std;

void print_dashs()
{
  cout << "-------------------------------------------------------------------------\n";
}

string tabs_(int num)
{
  string t = "";
  for (short i = 0; i < num; i++)
    t.append("\t");
  return t;
}

void print_header(short vec_length)
{
    cout << tabs_(3) << "  Client List (" << vec_length << ") Client(s).\n";
    print_dashs();
    
    cout << "| " << left << setw(15) << "Account Number"
         << "| " << left << setw(10) << "Pin Code"
         << "| " << left << setw(20) << "Client Name"
         << "| " << left << setw(14) << "Phone"
         << "| " << left << setw(12) << "Balance"
         << "\n";
         
    print_dashs();
}


void print_header_balances(short vec_length)
{
    cout << tabs_(3) << "  Client List (" << vec_length << ") Client(s).\n";
    print_dashs();
    
    cout << "| " << left << setw(15) << "Account Number"
         << "| " << left << setw(20) << "Client Name"
         << "| " << left << setw(12) << "Balance"
         << "\n";
         
    print_dashs();
}

void print_footer()
{
  print_dashs();
}

void UpdateClientInfo(clsBankClient &client)
{
  string FirstName = clsInput::readStringOptional("Enter client First Name", "First Name");
  string LastName = clsInput::readStringOptional("Enter client Last Name", "Last Name");
  string Email = clsInput::readStringOptional("Enter client Email", "Enter client Email");
  string Phone = clsInput::readStringOptional("Enter client Phone", "Phone");
  string PinCode = clsInput::readStringOptional("Enter the Pin Code", "Pin Code");
  if (FirstName.length() != 0)
    client.SetFirstName(FirstName);
  if (LastName.length() != 0)
    client.SetLastName(LastName);
  if (Email.length() != 0)
    client.SetEmail(Email);
  if (Phone.length() != 0)
    client.SetPhone(Phone);
  if (PinCode.length() != 0)
    client.setPinCode(PinCode);
}

void ReadClientInfo(clsBankClient &client)
{
  string FirstName = clsInput::readString("Enter client First Name");
  string LastName = clsInput::readString("Enter client Last Name");
  string Email = clsInput::readString("Enter client Email");
  string Phone = clsInput::readString("Enter client Phone");
  string PinCode = clsInput::readString("Enter the Pin Code");
  string Balance = clsInput::readString("Enter the Balance");
  if (FirstName.length() != 0)
    client.SetFirstName(FirstName);
  if (LastName.length() != 0)
    client.SetLastName(LastName);
  if (Email.length() != 0)
    client.SetEmail(Email);
  if (Phone.length() != 0)
    client.SetPhone(Phone);
  if (PinCode.length() != 0)
    client.setPinCode(PinCode);
  if (Balance.length() != 0)
    client.setAccountBalance(stof(Balance));
}

void UpdateClient()
{
  string AccountNumber = clsInput::readString("Enter account Number");

  clsBankClient client = clsBankClient::Find(AccountNumber);

  while (client.IsEmpty())
  {
    cout << "No Client Exists with this Account Number" << endl;
    AccountNumber = clsInput::readString("Enter account Number");
    client = clsBankClient::Find(AccountNumber);
  }

  UpdateClientInfo(client);

  clsBankClient::enSaveResults result = client.Save();
  switch (result)
  {
  case clsBankClient::enSaveResults::svSuceeded:
    cout << "Succeeded!" << endl;
    break;

  case clsBankClient::enSaveResults::svFailedEmptyObject:
    cout << "Empty!" << endl;
    break;

  default:
    break;
  }
}

void AddClient()
{
  string AccountNumber = clsInput::readString("Enter account Number");

  clsBankClient client = clsBankClient::Find(AccountNumber);

  while (!client.IsEmpty())
  {
    cout << "This account number already in use" << endl;
    AccountNumber = clsInput::readString("Enter account Number");
    client = clsBankClient::Find(AccountNumber);
  }

  client = clsBankClient::getAddNewClient(AccountNumber);

  ReadClientInfo(client);

  clsBankClient::enSaveResults result = client.Save();

  switch (result)
  {
  case clsBankClient::enSaveResults::svSuceeded:
    cout << "Succeeded!" << endl;
    break;

  case clsBankClient::enSaveResults::svFailedAccountInUse:
    cout << "Account Already in use!" << endl;
    break;

  default:
    break;
  }
}

void DeleteClient()
{
  string AccountNumber = clsInput::readString("Enter account Number");

  clsBankClient client = clsBankClient::Find(AccountNumber);

  while (client.IsEmpty())
  {
    cout << "No Client Exists with this Account Number" << endl;
    AccountNumber = clsInput::readString("Enter account Number");
    client = clsBankClient::Find(AccountNumber);
  }

  bool deleted = client.Delete();

  if (deleted)
    cout << "Client Deleted Successfully" << endl;
  else
    cout << "No Client is deleted" << endl;
}

void ListClients()
{
    vector<clsBankClient> clients = clsBankClient::ClientList();
    print_header(clients.size());

    for (clsBankClient &c : clients)
    {
        cout << "| " << left << setw(15) << c.GetAccountNumber()
             << "| " << left << setw(10) << c.GetPinCode()
             << "| " << left << setw(20) << (c.GetFirstName() + " " + c.GetLastName())
             << "| " << left << setw(14) << c.GetPhone()
             << "| " << left << setw(12) << c.getAccountBalance()
             << endl;
    }
    
    print_dashs();
}

void ListBalances()
{
    vector<clsBankClient> clients = clsBankClient::ClientList();
    print_header(clients.size());

    for (clsBankClient &c : clients)
    {
        cout << "| " << left << setw(15) << c.GetAccountNumber()
             << "| " << left << setw(20) << (c.GetFirstName() + " " + c.GetLastName())
             << "| " << left << setw(12) << c.getAccountBalance()
             << endl;
    }
    
    print_dashs();
    double summation = clsBankClient::GetSumOfBalances();
    cout << left << setw(10) << "Client Total Balances (" << summation << ") Dollar(s)." << endl;
    cout << left << setw(10) << clsUtil::numberToWords(int(summation))<< endl;
    print_dashs();
    cout << endl;
}

int main()
{

  ListBalances();

  return 0;
}