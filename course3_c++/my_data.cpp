#include <iostream>
using namespace std;

enum Gender { F, M };
enum Marital_status { Single, Married };

struct Person {
    string name;
    string country;
    int age;    
    string city;
    char gender;
    int monthly_salary;
    int yearly_salary;
    Marital_status married;
};

int main() {
    Person p;
    bool marital_status;

    cout << "Enter your name\n";
    cin >> p.name;
    cout << "\n";

    cout << "Enter your age\n";
    cin >> p.age;
    cout << "\n";


    cout << "Enter your country\n";
    cin >> p.country;
    cout << "\n";

    cout << "Enter your city\n";
    cin >> p.city;
    cout << "\n";

    cout << "Enter your gender\n";
    cin >> p.gender;
    cout << "\n";

    cout << "Enter your monthly salary\n";
    cin >> p.monthly_salary;
    cout << "\n";

    p.yearly_salary = p.monthly_salary * 12;


    cout << "Enter your marital status (choose 0 for single, 1 for married)\n";
    cin >> marital_status;
    cout << "\n";


    cout << "Name: " << p.name << "\n";
    cout << "Age: " << p.age << "\n";
    cout << "Country: " << p.country << "\n";
    cout << "City: " << p.city << "\n";
    cout << "Monthly Salary: " << p.monthly_salary << "\n";
    cout << "Yearly Salary: " << p.yearly_salary << "\n";
    cout << "Gender: " << p.gender << "\n";
    if (marital_status) {
        cout << "Married: Yes \n";
        p.married = Single;
    }
    else {
       cout << "Married: No \n";
       p.married = Married;
    }
}