#pragma once
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsHelper.h"
#include "clsInput.h"
#include "clsDate.h"

class clsUser : public clsPerson
{
public:
  struct stLoggingRegister {
    string DateTime;
    string Username;
    string Password;
    string permissions;
  };
private:
  enum enMode
  {
    EmptyMode = 0,
    UpdateMode = 1,
    AddNew = 2
  };
  enMode _Mode;
  string _Username;
  string _Password;
  int _Permissions;
  bool _MarkForDelete;

  static vector<string> _ObjectToVector(clsUser &user)
  {
    return {
        user.GetFirstName(),
        user.GetLastName(),
        user.GetEmail(),
        user.GetPhone(),
        user.GetUsername(),
        user.GetPassword(),
        to_string(user.GetPermissions())
    };
  }

  static string _GenerateRecord(clsUser &user)
  {
    vector<string> vec = _ObjectToVector(user);
    return clsString::join(vec, "//#");
  }

  static vector<string> _GenerateRecords(vector<clsUser> vec)
  {
    vector<string> vec_records;
    for (clsUser &c : vec)
      vec_records.push_back(_GenerateRecord(c));
    return vec_records;
  }

  static clsUser _VectorToObject(vector<string> &vec)
  {
    return clsUser(enMode::UpdateMode, vec[0], vec[1], vec[2], vec[3], vec[4], vec[5], enPermissions(stoi(vec[6])));
  }

  static clsUser _GetEmptyObject()
  {
    return clsUser(enMode::EmptyMode, "", "", "", "", "", "", None);
  }

  static clsUser _RecordToObject(string record)
  {
    vector<string> vec;
    clsString::words_to_vec(record, vec, "//#");

    if (vec.size() < 7)
      return _GetEmptyObject();

    return _VectorToObject(vec);
  }

  static vector<string> _ReadUsersFromFile(string filename)
  {
    fstream file;
    clsHelper::open_file(file, filename, 'r');
    string line;
    vector<string> vec;
    while (getline(file, line))
      vec.push_back(line);
    file.close();
    return vec;
  }

  static void _SaveRecordsToFile(string filename, vector<string> records, char mode='a') {
    fstream file;
    clsHelper::open_file(file, filename, mode);
    if (file.is_open()) {
      for (string &s : records)
        file << s << "\n";
    }
    file.close();
  }


  static vector<clsUser> _FilterMarkedForDelete(vector<clsUser> users) {
    vector<clsUser> filtered;
    for (clsUser &c : users)
    {
      if (c.MarkForDelete())
        continue;
      filtered.push_back(c);
    }
    return filtered;
  }

  static void _WriteUsersToFile(vector<clsUser> users) {
    vector<string> str_vec = _GenerateRecords(_FilterMarkedForDelete(users));
    _SaveRecordsToFile("users.txt", str_vec, 'w');
  }

  static vector<clsUser> _StrVecToObjVec(vector<string> users, string delim = "//#")
  {
    vector<clsUser> vec;
    vector<string> substring;
    for (string &s : users)
    {
      vector<string> substring;
      clsString::words_to_vec(s, substring, delim);
      vec.push_back(clsUser(enMode::UpdateMode, substring[0], substring[1], substring[2], substring[3], substring[4], substring[5], enPermissions(stoi(substring[6]))));
    }
    return vec;
  }

  static stLoggingRegister _ConvertToStructLoggingRegister(string line) {
    stLoggingRegister user;
    vector<string> splitted;
    clsString::words_to_vec(line, splitted, "//#");
    user.DateTime = splitted[0];
    user.Username = splitted[1];
    user.Password = splitted[2];
    user.permissions = splitted[3];
    return user;
  }

  bool _Update() {
    vector<string> users_str = _ReadUsersFromFile("users.txt");
    bool found = false;
    for (string &s : users_str)
    {
      clsUser user_before_update = _RecordToObject(s);
      if (user_before_update.GetUsername() == this->GetUsername())
      {
        s = _GenerateRecord(*this);
        found = true;
        break;
      }
    }
    if (found)
      _WriteUsersToFile(_StrVecToObjVec(users_str));
    
    return found;
  }

  bool _Delete() {
    vector<clsUser> users = _StrVecToObjVec(_ReadUsersFromFile("users.txt"));
    bool found = false;
    for (clsUser &c : users)
    {
      if (c.GetUsername() == this->GetUsername())
      {
        c._MarkForDelete = true;
        found = true;
      }
    }
    *(this) = _GetEmptyObject();
    _WriteUsersToFile(users);
    return found;
  }

  void _AddRecordToFile(string record, string filename) {
    fstream file;
    clsHelper::open_file(file, filename, 'a');
    file << record + "\n";
    file.close();
  }
  void _Add() {
    _AddRecordToFile(_GenerateRecord(*this), "users.txt");
  }

public:
  enum enPermissions
  {
    None = 0,
    All = -1,
    ClientList = 1,
    AddClient = 2,
    DeleteClient = 4,
    UpdateClient = 8,
    FindClient = 16,
    Transactions = 32,
    ManageUsers = 64,
    LoginRegister = 128,
    CurrencyExchange = 164
  };

  enum enSaveResults { svFailedEmptyObject = 0, svSuceeded = 1, svFailedAccountInUse = 2 };

  clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int permissions) : clsPerson(FirstName, LastName, Email, Phone)
  {
    _Mode = Mode;
    _Username = Username,
    _Password = Password,
    _MarkForDelete = false;
    _Permissions = enPermissions(permissions);
  };

  bool IsEmpty()
  {
    return (_Mode == enMode::EmptyMode);
  }

  bool MarkForDelete() {
    return _MarkForDelete;
  }

  string GetUsername() {
    return _Username;
  }

  string GetPassword() {
    return  _Password;
  }

  int GetPermissions() {
    return  int(_Permissions);
  }

  void SetUsername(string Username) {
    _Username = Username;
  }

  void SetPassword(string Password) {
    _Password = Password;
  }

  void SetPermissions(int permissions) {
    _Permissions = (enPermissions)permissions;
  }

  static clsUser Find(string Username)
  {
    vector<string> vec = _ReadUsersFromFile("users.txt");
    
    for (string &s : vec)
    {
      clsUser c = _RecordToObject(s);
      if (c.GetUsername() == Username)
        return c;
    }
    return _GetEmptyObject();
  }

  static clsUser Find(string Username, string Password)
  {
    vector<string> vec = _ReadUsersFromFile("users.txt");
    for (string &s : vec)
    {
      clsUser c = _RecordToObject(s);
      if (c.GetUsername() == Username && c.GetPassword() == Password)
        return c;
    }
    return _GetEmptyObject();
  }

  static bool IsUserExist(string Username)
  {
    return (!Find(Username).IsEmpty());
  }

  static clsUser GetAddNewUser(string Username) {
    return clsUser(enMode::AddNew, "", "", "", "", Username, "", None);
  }

  bool Delete() {
    bool wantToDelete = clsInput::wants_to_enter("Do you really want to delete this user ?");
    bool result = false;
    if(wantToDelete)
      result = _Delete();
    return result;
  } 

  static vector<clsUser> UserList() {
    return _StrVecToObjVec(_ReadUsersFromFile("users.txt"));
  }

  static bool CheckPermissions(enPermissions userPermissions, enPermissions reqPermissions) {
    if ((enPermissions)userPermissions == All)
      return true;
    if (((int)userPermissions & (int)reqPermissions) == (int)reqPermissions)
      return true;
    return false;
  }

  static void AddToLogFile(string username, string password) {
      clsUser user = clsUser::Find(username, password);
      int permissions = !user.IsEmpty() ? user.GetPermissions() : 0;
      string RegisterRecord = clsDate::getNowDateAndTime() + "//#" + username + "//#" + clsUtil::EncryptText(password, 4) + "//#" + to_string(permissions);
      fstream file;
      clsHelper::open_file(file, "loginRegister.txt", 'a');
      file << RegisterRecord << endl;
      file.close();
  }

  static vector<stLoggingRegister> GetLoggedInUsers() {
    fstream file;
    vector<stLoggingRegister> users;
    clsHelper::open_file(file, "loginRegister.txt", 'r');
    string line;
    while (getline(file, line)) {
      users.push_back(_ConvertToStructLoggingRegister(line));
    }
    return users;
  }

  enSaveResults Save() {
    switch (_Mode)
    {
      case enMode::EmptyMode:
        return enSaveResults::svFailedEmptyObject;

      case enMode::UpdateMode:
      {
        bool result = _Update();
        return result ? enSaveResults::svSuceeded : enSaveResults::svFailedEmptyObject;
      }

      case enMode::AddNew:       
      {
        if (IsUserExist(this->GetUsername()))
          return enSaveResults::svFailedAccountInUse;
        _Add();
        _Mode = enMode::UpdateMode;
        return enSaveResults::svSuceeded;
      }

      default:
        break;
    }
  }
};
