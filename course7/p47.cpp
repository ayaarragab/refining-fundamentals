#include "my_string_funcs.h"
#include <fstream>

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

int main() {
  save_clients_data_to_file();
  return 0;
}
