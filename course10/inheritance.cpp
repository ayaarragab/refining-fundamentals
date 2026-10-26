#include <iostream>
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
};

int main() {
  clsEmployee employee("A1223", "Aya", "R.", "A@A.COM", "010232242", "Software Engineer", 1000000);
  
  cout << employee.getFirstName() << endl;
  cout << employee.getLastName() << endl;
  cout << employee.getSalary() << endl;
  return  0;
}