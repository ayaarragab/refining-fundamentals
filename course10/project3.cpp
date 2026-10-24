#include <iostream>
using namespace std;

class clsEmployee {
  private:
    string _id;
    string _firstName;
    string _lastName;
    string _phone;
    string _email;
    string _fullName;
    string _title;
  
  public:
    clsEmployee(string id, string firstName, string lastName, string email, string phone, string title) {
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

    string getTitle() {
      return _title;
    }

    void setTitle(string title) {
      _title = title;
    }

    void sendEmail(string subject, string body) {
      cout << "Email Sent";
    }

    void sendSMS(string body) {
      cout << "Email Sent";
    }
};

int main() {
  clsEmployee person("12", "Aya", "Ragab", "aya@gmail.com", "012323321", "Software Engineer");
  cout << person.getEmail() << endl;
  person.setLastName("R");
  cout << person.getLastName() << endl;
  person.sendEmail("Job Application", "Body");
  return  0;
}