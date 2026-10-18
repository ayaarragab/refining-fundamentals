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

  vector<string> generate_records(vector<stClientData> &vec) {
    vector<string> vec_records;
    for (stClientData &c : vec)
      vec_records.push_back(generate_record(c));
    return vec_records;
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

  void open_file(fstream &f, string filename, char mode='r') {
    switch (mode)
    {
    case 'a':
      f.open(filename, ios::out | ios::app);
      break;
    case 'w':
      f.open(filename, ios::out);
      break;
    case 'r':
      f.open(filename, ios::in);
      break;
    default:
      break;
    }
  }

  void save_records_to_file(string filename, vector<string> records, char mode='a') {
    fstream file;
    open_file(file, filename, 'w');
    if (file.is_open()) {
      for (string &s : records)
        file << s << "\n";
    }
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

  void print_dashs() {
    cout << "-------------------------------------------------------------------------\n";
  }

  string tabs_(int num) {
    string t = "";
    for (short i = 0; i < num; i++)
      t.append("\t");
    return t;
  }

  void print_header(short vec_length) {
    cout << tabs_(3) <<"  Client List (" << vec_length << ")" << " Client(s)."<< tabs_(3) << "\n";
    print_dashs();
    cout << "  Account Number |  Pin Code | Client Name " << setw(7) << "| " << "Phone  | " << "   Balance \n";
    print_dashs();
  }

  void print_footer() {
    print_dashs();
  }

  void print_clients(vector<stClientData> &vec) {
    print_header(vec.size());
    for (stClientData &c : vec)
      cout << setw(11)<< c.account_number << setw(7) << "|" << setw(8) << c.pin_code << setw(4) << "|" << setw(10) << c.name << setw(10) << "| " << c.phone << setw(6) << "| " << c.balance << endl;
    print_footer();
  }


  bool find_with_acc_num(string account_num, vector<stClientData> &vec, vector<stClientData>::iterator &iter) {
    vec = read_clients_file_and_convert_to_struct("clients.txt");
    iter = vec.begin();
    while (iter != vec.end())
    {
     if (iter->account_number == account_num)
     {
      print_client_data(*(iter));
      return true;
     }
     ++iter;
    }
    return false;
  }

  bool find_with_acc_num(string account_num) {
    vector<stClientData> vec = read_clients_file_and_convert_to_struct("clients.txt");
    vector<stClientData>::iterator iter = vec.begin();
    while (iter != vec.end())
    {
     if (iter->account_number == account_num)
     {
      print_client_data(*(iter));
      return true;
     }
     ++iter;
    }
    return false;
  }

  bool sure_to(bool update=false) {
    string delete_or_update = update ? "update" : "delete";
    char c = input_funcs::readCharacter("Are you sure you want to " + delete_or_update + " it? (y/n)");
    return c == 'y' || c == 'Y';
  }

  void write_vector_to_file(vector<stClientData> vec) {
    vector<string> vec_records = generate_records(vec);
    save_records_to_file("clients.txt", vec_records, 'w');
  }

  stClientData update_client(stClientData &c) {
    string account_number = input_funcs::readString("Enter account number:");
    string pin_code = input_funcs::readString("Enter pin code:");
    string name = input_funcs::readString("Enter your name:");
    string phone = input_funcs::readString("Enter account phone:");
    int balance = input_funcs::readNum("Enter your balance:");
    if (account_number != "")
      c.account_number =  account_number;
    if (pin_code != "")
      c.pin_code =  pin_code;
    if (name != "")
      c.name =  name;
    if (phone != "")
      c.phone =  phone;
    if (balance)
      c.balance = balance;
    return c;
  }

  void delete_with_acc_num(string account_num, bool display_sure=true) {
    vector<stClientData> vec;
    vector<stClientData>::iterator iter;
    bool found = find_with_acc_num(account_num, vec, iter);
    bool sure = true;
    if (found)
    {
      if (display_sure)
        sure = sure_to();
      if (sure)
      {
        vec.erase(iter);
        print_clients(vec);
        write_vector_to_file(vec);
      }
    }
  }

  void update_with_acc_num(string account_num) {
    vector<stClientData> vec;
    vector<stClientData>::iterator iter;
    stClientData c_new;
    bool found = find_with_acc_num(account_num, vec, iter);
    bool sure = true;
    if (found)
    {
      sure = sure_to(true);
      if (sure)
      {
        update_client(*(iter));
        print_clients(vec);
        write_vector_to_file(vec);
      }
    } else
      cout << "No clients exists with this acc number \n";
  }

  void display_clients() {
    vector<stClientData> vec = read_clients_file_and_convert_to_struct("clients.txt");
    print_clients(vec);
  }
} // namespace client_data_funcs
