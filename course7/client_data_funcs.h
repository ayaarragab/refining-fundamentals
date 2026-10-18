#include "my_string_funcs.h"
#include <fstream>
#include <iomanip>



namespace client_data_funcs
{
  struct stClientData {
    string account_number;
    string pin_code;
    string name;
    string phone;
    int balance;
  };
  void read_client_data(stClientData &client) {
    client.account_number = input_funcs::readString("Enter account number:");
    client.pin_code = input_funcs::readString("Enter pin code:");
    client.name = input_funcs::readString("Enter your name:");
    client.phone = input_funcs::readString("Enter account phone:");
    client.balance = input_funcs::readNum("Enter your balance:");
  }

  vector<string> client_data_to_vec(stClientData &client) {
    return {
      client.account_number,
      to_string(client.balance),
      client.name,
      client.phone,
      client.pin_code
    };
  }

  string generate_record(stClientData &client) {
    vector<string> vec = client_data_to_vec(client);
    return my_string_funcs::join(vec, "//#");
  }

  void vec_to_client_data(vector<string> &vec, stClientData &client) {
    client.account_number = vec[0];
    client.balance = stoi(vec[1]);
    client.name = vec[2];
    client.phone = vec[3];
    client.pin_code = vec[4];
  }

  stClientData record_to_client(string record) {
    stClientData client;
    vector<string> vec;
    my_string_funcs::words_to_vec(record, vec, "//#");
    vec_to_client_data(vec, client);
    return client;
  }

  void print_client_data(stClientData &client) {
    cout << "Acc Num: " << client.account_number << endl;
    cout << "Acc Balance: " << client.balance << endl;
    cout << "Acc Name: " << client.name << endl;
    cout << "Acc Phone: " << client.phone << endl;
    cout << "Acc Pin Code: " << client.pin_code << endl;
  }

  void save_record_to_file(string filename, string record) {
    fstream file;
    file.open(filename, ios::out | ios::app);
    if (file.is_open())
      file << record << "\n";
    file.close();
  }

  void save_clients_data_to_file() {
    stClientData client;
    bool wants_to_enter_again = true;
    while (wants_to_enter_again)
    {
      read_client_data(client);
      string record = generate_record(client);
      save_record_to_file("clients.txt", record);
      wants_to_enter_again = input_funcs::wants_to_enter();
    } 
  }

  vector<stClientData> read_clients_file_and_convert_to_struct(string filename) {
    fstream file;
    vector<stClientData> vec;
    file.open(filename, ios::in);
    if (file.is_open())
    {
      string line;
      while (getline(file, line))
        vec.push_back(record_to_client(line));
      file.close();
    }
    return vec;
  }

  void print_header(short vec_length) {
    cout << "\t\t\t  Client List (" << vec_length << ")" << " Client(s).\t\t\t\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << "  Account Number |  Pin Code | Client Name " << setw(7) << "| " << "Phone  | " << "   Balance \n";
    cout << "-------------------------------------------------------------------------\n";

  }

  void print_footer() {
    cout << "-------------------------------------------------------------------------\n";
  }

  void print_clients(vector<stClientData> &vec) {
    print_header(vec.size());
    for (stClientData &c : vec)
      cout << setw(11)<< c.account_number << setw(7) << "|" << setw(8) << c.pin_code << setw(4) << "|" << setw(10) << c.name << setw(10) << "| " << c.phone << setw(6) << "| " << c.balance << endl;
    print_footer();
  }
 

  void find_with_acc_num(string account_num) {
    vector<stClientData> vec = read_clients_file_and_convert_to_struct("clients.txt");
    for (stClientData &c : vec)
    {
     if (c.account_number == account_num)
      print_client_data(c);
      break;
    }
    cout << "No Clients found with this account number\n";
  }
} // namespace client_data_funcs
