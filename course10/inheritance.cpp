#include <iostream>
#include <iomanip>
using namespace std;

class clsPerson {
  private:
    string _id;
    string _firstName;
    string _lastName;
    string _phone;
    string _email;
    string _fullName;
  
  public:
    clsPerson(string id, string firstName, string lastName, string email, string phone) {
      _id = id;
      _firstName = firstName;
      _lastName = lastName;
      _email = email;
      _phone = phone;
    }
    string getId() {
      return _id;
    }
    string getFirstName() {
      return _firstName;
    }

    void setFirstName(string firstName) {
      _firstName = firstName;
    }
  
    string getLastName() {
      return _lastName;
    }

    void setLastName(string lastname) {
      _lastName = lastname;
    }

    string getEmail() {
      return _email;
    }

    void setEmail(string email) {
      _email = email;
    }

    string getPhone() {
      return _phone;
    }

    void setPhone(string phone) {
      _phone = phone;
    }

    void sendEmail(string subject, string body) {
      cout << "Email Sent";
    }

    void sendSMS(string body) {
      cout << "Email Sent";
    }
  
    void print() {
      cout << "----------------------------------------------------" << endl;
      cout <<  setw(10) << "First Name: " << _firstName << setw(10) << endl;
      cout << setw(10) << "Last Name: " << _lastName << setw(10) << endl;
      cout << setw(10) << "ID: " << _id << setw(10) << endl;
      cout << setw(10) << "Email: " << _email << setw(10) << endl;
      cout << setw(10) <<"Phone: " << _phone << setw(10) << endl;
      cout << "----------------------------------------------------" << endl;
    }
};


class clsEmployee: public clsPerson {
  private:
    int _salary;
    string _title;
  public:
    clsEmployee(string id, string firstName, string lastName, string email, string phone, string title, int salary) : clsPerson (id, firstName, lastName, email, phone){
      _title = title;
      _salary = salary;
    }

    void setSalary(int salary) {
      _salary = salary;
    }
    int getSalary() {
      return _salary;
    }
    void setTitle(string title) {
      _title = title;
    }
    string getTitle() {
      return _title;
    }
    void print() {
      cout << "----------------------------------------------------" << endl;
      cout <<  setw(10) << "First Name: " << getFirstName() << setw(10) << endl;
      cout << setw(10) << "Last Name: " << getLastName() << setw(10) << endl;
      cout << setw(10) << "ID: " << getId() << setw(10) << endl;
      cout << setw(10) << "Email: " << getEmail() << setw(10) << endl;
      cout << setw(10) <<"Phone: " << getPhone() << setw(10) << endl;
      cout << setw(10) <<"Title: " << _title << setw(10) << endl;
      cout << setw(10) <<"Salary: " << _salary << setw(10) << endl;
      cout << "----------------------------------------------------" << endl;
    }
};

class clsProgrammer: public clsEmployee {
  private:
    string _programmingLanguage;

  public:
    clsProgrammer(string id, string firstName, string lastName, string email, string phone, string title, int salary, string programmingLanguage) : clsEmployee(id, firstName, lastName, email, phone, title, salary){
      _programmingLanguage = programmingLanguage;
    }
    void setMainProgrammingLanguage(string programmingLanguage) {
      _programmingLanguage = programmingLanguage;
    }
    string getMainProgrammingLanguage() {
      return _programmingLanguage;
    }
    void print() {
      cout << "----------------------------------------------------" << endl;
      cout <<  setw(10) << "First Name: " << getFirstName() << setw(10) << endl;
      cout << setw(10) << "Last Name: " << getLastName() << setw(10) << endl;
      cout << setw(10) << "ID: " << getId() << setw(10) << endl;
      cout << setw(10) << "Email: " << getEmail() << setw(10) << endl;
      cout << setw(10) <<"Phone: " << getPhone() << setw(10) << endl;
      cout << setw(10) <<"Title: " << getTitle() << setw(10) << endl;
      cout << setw(10) <<"Salary: " << getSalary() << setw(10) << endl;
      cout << setw(10) <<"Programming Language: " << _programmingLanguage << setw(10) << endl;
      cout << "----------------------------------------------------" << endl;
    }
};


int main() {
  clsProgrammer programmer("A1223", "Aya", "R.", "A@A.COM", "010232242", "Software Engineer", 1000000, "C++");
  
  cout << programmer.getFirstName() << endl;
  cout << programmer.getLastName() << endl;
  cout << programmer.getSalary() << endl;
  cout << programmer.getMainProgrammingLanguage() << endl;
  return  0;
}