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
    clsPerson() {}

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
    string _salary;
    string _title;
  public:
    void setSalary(string salary) {
      _salary = salary;
    }
    string getSalary() {
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
  clsEmployee employee;
  
  employee.setFirstName("Aya");
  employee.setLastName("R.");
  employee.setTitle("Software Engineer");
  cout << employee.getFirstName() << endl;
  cout << employee.getLastName() << endl;
  return  0;
}