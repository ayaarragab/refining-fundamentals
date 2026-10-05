#include <iostream>
using namespace std;

enum Gender { F, M };
enum Marital_status { Single, Married };

int main() {
    string name;
    string country;
    int age;    
    string city;
    char gender;
    int monthly_salary;
    int yearly_salary;
    Marital_status married;
    

    cout << "Enter your name\n";
    cin >> name;
    cout << "\n";

    cout << "Enter your age\n";
    cin >> age;
    cout << "\n";


    cout << "Enter your country\n";
    cin >> country;
    cout << "\n";

    cout << "Enter your city\n";
    cin >> city;
    cout << "\n";

    cout << "Enter your gender\n";
    cin >> gender;
    cout << "\n";

    cout << "Enter your monthly salary\n";
    cin >> monthly_salary;
    cout << "\n";

    yearly_salary = monthly_salary * 12;


    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Country: " << country << "\n";
    cout << "City: " << city << "\n";
    cout << "Monthly Salary: " << monthly_salary << "\n";
    cout << "Yearly Salary: " << yearly_salary << "\n";
    cout << "Gender: " << gender << "\n";
    if (married) {
        cout << "Married: Yes \n";
        married = Single;
    }
    else {
       cout << "Married: No \n";
       married = Married;
    }
    
}