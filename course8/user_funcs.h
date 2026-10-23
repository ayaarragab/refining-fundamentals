#pragma once
#include "my_string_funcs.h"
#include <fstream>
#include <iomanip>

namespace user_namspc
{
  struct stUser
  {
    string username;
    string password;
    int permissions;
  };

  enum enPermissions
  {
    All = -1,
    ClientList = 1,
    AddClient = 2,
    DeleteClient = 4,
    UpdateClient = 8,
    FindClient = 16,
    Transactions = 32,
    ManageUsers = 64
  };

  enum enManageUsersOp {
    ListUsers = 1,
    AddUsers = 2,
    DeleteUsers = 3,
    UpdateUsers = 4,
    FindUsers = 5,
    mMainMenu = 6
  };
  void print_users(vector<stUser> &users);
  void print_user(stUser &user);
  void give_permissions(stUser &user)
  {
    bool permisson;

    // ALL
    cout << "You want to give this user ALL permissions? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
    {
      user.permissions = -1;
      return;
    }
    // list client
    cout << "You want to give this user [1].ClientList permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)ClientList;

    // add client
    cout << "You want to give this user [2].AddClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)AddClient;

    // delete client
    cout << "You want to give this user [4].DeleteClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)DeleteClient;

    // update client
    cout << "You want to give this user [8].UpdateClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)UpdateClient;

    // Find Client
    cout << "You want to give this user [16].FindClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)FindClient;

    // Transactions
    cout << "You want to give this user [32].FindClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)FindClient;
  }
  
  void read_user_data_from_input(stUser &user)
  {
    user.username = input_funcs::readString("Enter username:");
    user.password = input_funcs::readString("Enter user password:");
    user.permissions = 0;
    give_permissions(user);
  }

  bool check_access(int userPermissions, enPermissions requiredPermissions)
  {
    if ((enPermissions)userPermissions == All)
      return true;
    if (((int)requiredPermissions & userPermissions) == (int)requiredPermissions)
      return true;
    return false;
  }

  void open_file(fstream &f, string filename, char mode = 'r')
  {
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

  vector<string> read_users_from_file(string filename)
  {
    fstream file;
    open_file(file, filename, 'r');
    string line;
    vector<string> vec;
    while (getline(file, line))
      vec.push_back(line);
    file.close();
    return vec;
  }

  vector<stUser> convert_users_to_vecStruct(vector<string> &users, string delim="//#") {
    vector<stUser> vec;
    vector<string> substring;
    stUser user;
    for (string &s : users)
    {
      vector<string> substring;
      my_string_funcs::words_to_vec(s, substring, delim);
      user.username = substring[0];
      user.password = substring[1];
      user.permissions = stoi(substring[2]);
      vec.push_back(user);
    }
    return vec;
  }

  stUser find_user(string username) {
    vector<stUser> users;
    vector<string> vec = read_users_from_file("users.txt");
    users = convert_users_to_vecStruct(vec);
    for (stUser &u : users)
    {
      if (u.username == username)
        return u;
    }
    return { "", "", 0 };
  }

  stUser find_user(string username, string password) {
    vector<stUser> users;
    vector<string> vec = read_users_from_file("users.txt");
    users = convert_users_to_vecStruct(vec);
    for (stUser &u : users)
    {
      if (u.username == username && u.password == password)
        return u;
    }
    return { "", "", 0 };
  }

  vector<string> user_struct_to_vec(stUser &user) {
    vector<string> vec;
    vec.push_back(user.username);
    vec.push_back(user.password);
    vec.push_back(to_string(user.permissions));
    return vec;
  }

  string generate_record(stUser &user) {
    vector<string> vec = user_struct_to_vec(user);
    return my_string_funcs::join(vec, "//#");
  }

  vector<string> generate_records(vector<stUser> &vec) {
    vector<string> vec_records;
    for (stUser &c : vec)
      vec_records.push_back(generate_record(c));
    return vec_records;
  }
  
  void save_records_to_file(string filename, vector<string> records, char mode='a') {
    fstream file;
    open_file(file, filename, mode);
    if (file.is_open()) {
      for (string &s : records)
        file << s << "\n";
    }
    file.close();
  }

  void write_vector_to_file(vector<stUser> vec) {
    vector<string> vec_records = generate_records(vec);
    save_records_to_file("users.txt", vec_records, 'w');
  }


  void add_user(stUser &user) {
    read_user_data_from_input(user);
    stUser user_found = find_user(user.username);
    
    if (user_found.username != "")
    {
      cout << "This user already exists!" << endl;
      return;
    }
    
    fstream file;
    open_file(file, "users.txt", 'a');
    file << generate_record(user) + "\n";
    file.close();
  }


  vector<stUser> load_users() {
    vector<string> users_str_vec = read_users_from_file("users.txt");
    vector<stUser> vec = convert_users_to_vecStruct(users_str_vec);
    return vec;    
  }
  
  bool sure_to(bool update=false) {
    string delete_or_update = update ? "update" : "delete";
    char c = input_funcs::readCharacter("Are you sure you want to " + delete_or_update + " it? (y/n)");
    return c == 'y' || c == 'Y';
  }

  bool find_in_vector(string username, vector<stUser> &vec, vector<stUser>::iterator &iter) {
    iter = vec.begin();
    while (iter != vec.end())
    {
     if (iter->username == username)
     {
      print_user(*(iter));
      return true;
     }
     ++iter;
    }
    return false;
  }

  void delete_user(string username, bool display_sure=true) {
    vector<stUser> vec = load_users();
    vector<stUser>::iterator iter;
    bool found = find_in_vector(username, vec, iter);
    bool sure = true;
    if (found)
    {
      if (display_sure)
        sure = sure_to();
      if (sure)
      {
        vec.erase(iter);
        print_users(vec);
        write_vector_to_file(vec);
      }
    }
  }

  stUser update_user(stUser &u) {
    string username = input_funcs::readString("Enter username:");
    string password = input_funcs::readString("Enter password:");  
    if (username != "")
      u.username = username;
    if (password != "")
      u.password = password;
    
    give_permissions(u);
    return u;
  }

  void update_user_in_file(string username) {
    vector<stUser> vec = load_users();
    vector<stUser>::iterator iter;
    bool found = find_in_vector(username, vec, iter);
    bool sure = true;
    if (found)
    {
      sure = sure_to(true);
      if (sure)
      {
        update_user(*(iter));
        print_users(vec);
        write_vector_to_file(vec);
      }
    } else
      cout << "No users exists with this username \n";
  }

  stUser login() {
    string username = input_funcs::readString("Enter username:");
    string password = input_funcs::readString("Enter user password:");
    stUser user = find_user(username, password);
    return user;
  }


  void print_users_header() {
    cout << "-------------------------------------------" << endl;
    cout << setw(15) << "Username" << setw(15) << "Password" << setw(15) << "Permissions" << endl;
    cout << "-------------------------------------------" << endl;
  }

  void print_user(stUser &user) {
    print_users_header();
    cout << setw(15) << user.username << setw(15) << user.password << setw(15) << user.permissions << endl;
  }


  void print_users(vector<stUser> &users) {
    print_users_header();
    for (stUser &u : users)
      print_user(u);
  }
} // namespace user_funcs
