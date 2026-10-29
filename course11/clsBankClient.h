#pragma once
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsHelper.h"

class clsBankClient : public clsPerson
{
  private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;

    static vector<string> _ObjectToVector(clsBankClient &client)
    {
      return {
          client._AccountNumber,
          to_string(client._AccountBalance),
          client.GetFirstName(),
          client.GetPhone(),
          client._PinCode};
    }

    static string _GenerateRecord(clsBankClient &client)
    {
      vector<string> vec = _ObjectToVector(client);
      return clsString::join(vec, "//#");
    }

    vector<string> _GenerateRecords(vector<clsBankClient> &vec)
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

    static clsBankClient _GetEmptyObject() {
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

    static vector<clsBankClient> _StrVecToObjVec(vector<string> &users, string delim="//#") {
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

  public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone){
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    };

    bool IsEmpty() {
      return (_Mode == enMode::EmptyMode);
    }

    string GetAccountNumber() {
      return _AccountNumber;
    }

    string getPinCode() {
      return _PinCode;
    }

    float getAccountBalance() {
      return _AccountBalance;
    }

    void setPinCode(string PinCode) {
      _PinCode = PinCode;
    }

    void setAccountBalance(float AccountBalance) {
      _AccountBalance = AccountBalance;
    }

    void setAccountNumber(string AccountNumber) {
      _AccountNumber = AccountNumber;
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

  static clsBankClient Find(string AccountNumber) {
    vector<string> vec = _ReadClientsFromFile("clients.txt");
    for (string &s : vec)
    {
      clsBankClient c = _RecordToObject(s);
      if (c.GetAccountNumber() == AccountNumber)
        return c;
    }
    return _GetEmptyObject();
  }

  static clsBankClient Find(string AccountNumber, string PinCode) {
    vector<string> vec = _ReadClientsFromFile("clients.txt");
    for (string &s : vec)
    {
      clsBankClient c = _RecordToObject(s);
      if (c.GetAccountNumber() == AccountNumber && c.getPinCode() == PinCode)
        return c;
    }
    return _GetEmptyObject();
  }
};

