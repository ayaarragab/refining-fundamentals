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

void ReadPerson(Person p) {
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

void fillPerson(Person p[2]) {
    for (short i = 0; i < 2; i++)
    {
        if (i > 0)
            cin.ignore(1, '\n');
        ReadPerson(p[i]);
    }
    
}

void printPerson(Person p[2]) {
    for (int i = 0; i < 2; i++)
    {
        cout << "\n";
        cout << "**********************************\n";
        cout << "Name: " << p[i].name << "\n";
        cout << "Age: " << p[i].age << "\n";
        cout << "Country: " << p[i].country << "\n";
        cout << "City: " << p[i].city << "\n";
        cout << "Monthly Salary: " << p[i].monthly_salary << "\n";
        cout << "Yearly Salary: " << p[i].yearly_salary << "\n";
        cout << "Gender: " << p[i].gender << "\n";
        if (p[i].married)
            cout << "Married: Yes \n";
        else
        cout << "Married: No \n";
        cout << "**********************************\n";
        cout << "\n";
    }
    
}

int main() {
    Person persons[2];
    fillPerson(persons);
    printPerson(persons);
}