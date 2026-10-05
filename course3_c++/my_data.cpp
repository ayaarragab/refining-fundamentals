#include <iostream>
using namespace std;

int main() {
    string name = "Aya Ragab";
    string country = "Egypt";
    int age = 22;    
    string city = "Giza";
    char gender = 'F';
    int monthly_salary = 3000;
    int yearly_salary = monthly_salary * 12;
    bool married = false;
    
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Country: " << country << "\n";
    cout << "City: " << city << "\n";
    cout << "Monthly Salary: " << monthly_salary << "\n";
    cout << "Yearly Salary: " << yearly_salary << "\n";
    cout << "Gender: " << gender << "\n";
    if (married)
        cout << "Married: Yes \n";
    else
        cout << "Married: No \n";
    
}