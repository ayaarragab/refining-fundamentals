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

void fillPerson(Person &p) {
    bool marital_status;
    
    cout << "Enter your name\n";
    getline(cin, p.name);
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

    if (marital_status)
        p.married = Marital_status::Married;
    else
        p.married = Marital_status::Single;
}

void printPerson(Person p) {
    cout << "Name: " << p.name << "\n";
    cout << "Age: " << p.age << "\n";
    cout << "Country: " << p.country << "\n";
    cout << "City: " << p.city << "\n";
    cout << "Monthly Salary: " << p.monthly_salary << "\n";
    cout << "Yearly Salary: " << p.yearly_salary << "\n";
    cout << "Gender: " << p.gender << "\n";
    if (p.married)
        cout << "Married: Yes \n";
    else
       cout << "Married: No \n";
}

int main() {
    Person p;
    fillPerson(p);
    printPerson(p);
}