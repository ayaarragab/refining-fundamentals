#include <iostream>
#include <cmath>
using namespace std;

int readNum(string message)
{
    int n;
    cout << message;
    cin >> n;
    return n;
}
int num_of_days_in_month(int month, int year);

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int num_of_days(int month, int year)
{
    return num_of_days_in_month(month, year);
}

int num_of_hours(int month, int year)
{
    return num_of_days(month, year) * 24;
}

int num_of_minutes(int month, int year)
{
    return num_of_hours(month, year) * 60;
}

int num_of_seconds(int month, int year)
{
    return num_of_minutes(month, year) * 60;
}

int num_of_days_in_month(int month, int year)
{
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return 28 + (is_leap_year(year) ? 1 : 0);
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return 0;
    }
}

string name_of_day(int day) {
    switch (day)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednsday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    default:
        return "";
    }
}

string name_of_month(int month) {
    std::string months[] = {
        "", "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };
    return months[month];
}

void read_date(int &day, int &month, int &year) {
    year = readNum("Enter the year:\n");
    month = readNum("Enter the month:\n");
    day = readNum("Enter the day:\n");
}

int calculate_day_number(int day, int month, int year) {
    double a = (14 - double(month)) / 12;
    double y = year - a;
    double m = month + (12 * a) - 2;
    int d = int(day + y + floor(y/4) - floor(y / 100) + floor(y / 400) + floor((31 * m) / 12)) % 7;
    return d;
}

string MonthShortName(short MonthNumber)
{
        string Months[12] = { "Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"
        };
        return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;
    // Index of the day from 0 to 6
    int current = calculate_day_number(1, Month, Year);
    NumberOfDays = num_of_days_in_month(Month, Year);
    // Print the current month name
    printf("\n _______________%s_______________\n\n",
    MonthShortName(Month).c_str());
    // Print the columns
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
    printf(" ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
    printf("%5d", j);
    if (++i == 7)
    {
    i = 0;
    printf("\n");
    }
    }
    printf("\n _________________________________\n");
}

int how_many_days_since(int day, int month, int year) {
    int days = 0;
    for (short i = 1; i < month; i++)
        days += (num_of_days_in_month(i, year));
    days += day;
    return days;
}

string days_to_date(int days, int year) {
    int d = 0;
    short i;
    for(i = 1; (d + num_of_days_in_month(i, year)) < days; i++)
        days += (num_of_days_in_month(i, year));
    int month_in_date = i;
    int day_in_date;
    int days_of_current_month = num_of_days(i, year);
    string date = "";
    if ((days - d) <= days_of_current_month)
        day_in_date = days - d;
    else {
        day_in_date = (days - d) - days_of_current_month;
        month_in_date = i + 1;
    }
    date.append(to_string(day_in_date));
    date.append(1, '-');
    date.append(to_string(month_in_date));
    date.append(1, '-');
    date.append(to_string(year));
    date.append(1, '\n');
    return date;
}

int main()
{
    int year, day, month;
    read_date(day, month, year);
    cout << "it's been " << how_many_days_since(day, month, year) << " day(s) since " << day << "-" << month << "-" << year << endl;
    cout << "back to date " << days_to_date(how_many_days_since(day, month, year), year);
    return 0;
}
