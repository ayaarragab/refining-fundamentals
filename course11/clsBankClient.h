#pragma once
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsHelper.h"

class clsBankClient : public clsPerson
{
private:
  enum enMode
  {
    EmptyMode = 0,
    UpdateMode = 1,
    AddNew = 2
  };
  enMode _Mode;
  string _AccountNumber;
  string _PinCode;
  float _AccountBalance;

  static vector<string> _ObjectToVector(clsBankClient &client)
  {
    return {
        client.GetFirstName(),
        client.GetLastName(),
        client.GetEmail(),
        client.GetPhone(),
        client.GetAccountNumber(),
        client.getPinCode(),
        to_string(client.getAccountBalance())
    };
  }

  static string _GenerateRecord(clsBankClient &client)
  {
    vector<string> vec = _ObjectToVector(client);
    return clsString::join(vec, "//#");
  }

  static vector<string> _GenerateRecords(vector<clsBankClient> &vec)
  {
    vector<string> vec_records;
    for (clsBankClient &c : vec)
      vec_records.push_back(_GenerateRecord(c));
    return vec_records;
  }

  static clsBankClient _VectorToObject(vector<string> &vec)
  {
    return clsBankClient(enMode::UpdateMode, vec[0], vec[1], vec[2], vec[3], vec[4], vec[5], stof(vec[6]));
  }

  static clsBankClient _GetEmptyObject()
  {
    return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
  }

  static clsBankClient _RecordToObject(string record)
  {
    vector<string> vec;
    clsString::words_to_vec(record, vec, "//#");

    if (vec.size() < 7)
      return _GetEmptyObject();

    return _VectorToObject(vec);
  }

  static vector<string> _ReadClientsFromFile(string filename)
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

  static void _WriteClientsToFile(vector<clsBankClient> clients) {
    vector<string> str_vec = _GenerateRecords(clients);
    _SaveRecordsToFile("clients.txt", str_vec, 'w');
  }

  static vector<clsBankClient> _StrVecToObjVec(vector<string> &users, string delim = "//#")
  {
    vector<clsBankClient> vec;
    vector<string> substring;
    for (string &s : users)
    {
      vector<string> substring;
      clsString::words_to_vec(s, substring, delim);
      vec.push_back(clsBankClient(enMode::UpdateMode, substring[0], substring[1], substring[2], substring[3], substring[4], substring[5], stof(substring[6])));
    }
    return vec;
  }

  bool _Update() {
    vector<string> clients_str = _ReadClientsFromFile("clients.txt");
    bool found = false;
    for (string &s : clients_str)
    {
      clsBankClient client_before_update = _RecordToObject(s);
      if (client_before_update.GetAccountNumber() == this->GetAccountNumber())
      {
        cout << _GenerateRecord(*this) << endl;
        s = _GenerateRecord(*this);
        found = true;
        break;
      }
    }
    if (found)
      _WriteClientsToFile(_StrVecToObjVec(clients_str));
    
    return found;
  }

  void _AddRecordToFile(string record, string filename) {
    fstream file;
    clsHelper::open_file(file, filename, 'a');
    file << record + "\n";
    file.close();
  }

  void _Add() {
    _AddRecordToFile(_GenerateRecord(*this), "clients.txt");
  }

public:
  enum enSaveResults { svFailedEmptyObject = 0, svSuceeded = 1, svFailedAccountInUse = 2 };

  clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
  {
    _Mode = Mode;
    _AccountNumber = AccountNumber;
    _PinCode = PinCode;
    _AccountBalance = AccountBalance;
  };

  bool IsEmpty()
  {
    return (_Mode == enMode::EmptyMode);
  }

  string GetAccountNumber()
  {
    return _AccountNumber;
  }

  string getPinCode()
  {
    return _PinCode;
  }

  float getAccountBalance()
  {
    return _AccountBalance;
  }

  void setPinCode(string PinCode)
  {
    _PinCode = PinCode;
  }

  void setAccountBalance(float AccountBalance)
  {
    _AccountBalance = AccountBalance;
  }

  void Print()
  {
    cout << "Account Name: " << this->GetFirstName() + " " + this->GetLastName() << endl;
    cout << "Account Phone: " << this->GetPhone() << endl;
    cout << "Account Email: " << this->GetEmail() << endl;
    cout << "Account Number: " << _AccountNumber << endl;
    cout << "Account Balance: " << _AccountBalance << endl;
    cout << "Account Pin Code: " << _PinCode << endl;
  }

  static clsBankClient Find(string AccountNumber)
  {
    vector<string> vec = _ReadClientsFromFile("clients.txt");
    for (string &s : vec)
    {
      clsBankClient c = _RecordToObject(s);
      if (c.GetAccountNumber() == AccountNumber)
        return c;
    }
    return _GetEmptyObject();
  }

  static clsBankClient Find(string AccountNumber, string PinCode)
  {
    vector<string> vec = _ReadClientsFromFile("clients.txt");
    for (string &s : vec)
    {
      clsBankClient c = _RecordToObject(s);
      if (c.GetAccountNumber() == AccountNumber && c.getPinCode() == PinCode)
        return c;
    }
    return _GetEmptyObject();
  }

  static bool IsClientExist(string AccountNumber)
  {
    return (!Find(AccountNumber).IsEmpty());
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
        if (IsClientExist(this->GetAccountNumber()))
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
