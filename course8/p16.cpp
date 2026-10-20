#include <iostream>
#include <cmath>
using namespace std;

struct stDate {
    int day;
    int month;
    int year;
};

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

void read_date(stDate &date) {
    date.year = readNum("Enter the year:\n");
    date.month = readNum("Enter the month:\n");
    date.day = readNum("Enter the day:\n");
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

string convert_arr_to_date(stDate date_struct) {
    string date = "";
    date.append(to_string(date_struct.day));
    date.append(1, '-');
    date.append(to_string(date_struct.month));
    date.append(1, '-');
    date.append(to_string(date_struct.year));
    date.append(1, '\n');
    return date;
}

string add_days_to_date(int days, stDate date) {
    int days_to_decrement = days + how_many_days_since(date.day, date.month, date.year);
    date.month = 1;
    while (true)
    {
        if (days_to_decrement > num_of_days_in_month(date.month, date.year))
        {
            days_to_decrement -= num_of_days_in_month(date.month, date.year);
            ++date.month;
            if (date.month > 12)
            {
                date.month = 1;
                ++date.year;
            }
        } else {
            date.day = days_to_decrement;
            break;
        }
    }
    return convert_arr_to_date(date);
}

bool last_day_in_year(stDate date) {
    return (date.day == 31) && (date.month == 12);
}

bool last_day_in_month(stDate date) {
    return date.day == num_of_days_in_month(date.month, date.year);
}

void increase_date(stDate &date) {
    if (last_day_in_year(date))
    {
        date.month = 1;
        date.day = 1;
        ++date.year;
    }
    else if (last_day_in_month(date))
    {
       ++date.month;
       date.day = 1;
    }
    else
        ++date.day;
}

void print_date(stDate date) {
    cout << date.day << "-" << date.month << "-" << date.year << endl;
}

int main()
{
    stDate date;
    read_date(date);
    increase_date(date);
    print_date(date);
    return 0;
}
