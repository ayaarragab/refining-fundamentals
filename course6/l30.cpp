#include <vector>
#include "input_funcs.h"
#include "print_funcs.h"
using namespace input_funcs;
using namespace print_funcs;

struct stEmployee {
  string first_name;
  string last_name;
  string code;
};

void print_employee(stEmployee &emp) {
  cout << "First Name: " << emp.first_name << "\n";
  cout << "Last Name: " << emp.last_name << "\n";
  cout << "Code: " << emp.code << "\n";
}

void print_vector_int(vector <stEmployee> &employees) {
  for (stEmployee &emp : employees)
    print_employee(emp);
}

void read_employee_data(stEmployee &employee) {
  employee.first_name = readString("Enter your first name!");
  employee.last_name = readString("Enter your last name!");
  employee.code = readString("Enter your code!");
}

void loop_untill_finish(vector <stEmployee> &vEmployees) {
  bool enter_again = true;
  
  while (enter_again)
  {
    stEmployee employee;
    read_employee_data(employee);
    vEmployees.push_back(employee);
    enter_again = input_funcs::wants_to_enter();
  }
}

int main() {
  vector <stEmployee> vEmployees;
 
  loop_untill_finish(vEmployees);
 
  for (stEmployee &e : vEmployees)
    print_employee(e);
  
  return 0;
}