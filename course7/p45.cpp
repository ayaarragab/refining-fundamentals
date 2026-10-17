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
  vec.push_back(client.account_number);
  vec.push_back(to_string(client.balance));
  vec.push_back(client.name);
  vec.push_back(client.phone);
  vec.push_back(client.pin_code);
  return vec;
}

string generate_record(stClientData &client) {
  vector<string> vec = client_data_to_vec(client);
  return my_string_funcs::join(vec, "//#");
}

int main() {
  stClientData client;
  read_client_data(client);
  cout << "Your record is: " << generate_record(client) << endl;
  return 0;
}
