#include "my_string_funcs.h"

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
  vector<string> vec;
  vec[0] = client.account_number;
  vec[1] = to_string(client.balance);
  vec[2] = client.name;
  vec[3] = client.phone;
  vec[4] = client.pin_code;
  return vec;
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

int main() {
  string s = "a212//#100//#a212//#a212//#a21";
  stClientData client;
  client = record_to_client(s);
  print_client_data(client);
  return 0;
}
