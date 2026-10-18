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

int* decide_day_month(int days_minus_, int days_of_curr_month, int current_month) {
    int day_in_date, month_in_date = current_month;
    int* ptr = new int[2];
    if (days_minus_ <= days_of_curr_month)
        day_in_date = days_minus_;
    else {
        day_in_date = days_minus_ - days_of_curr_month;
        month_in_date = current_month + 1;
    }
    *(ptr) = day_in_date;
    *(ptr + 1) = month_in_date;
    return ptr;
}

string convert_arr_to_date(int* &curr_day_and_month, int year) {
    string date = "";
    date.append(to_string(*(curr_day_and_month)));
    date.append(1, '-');
    date.append(to_string(*(curr_day_and_month + 1)));
    date.append(1, '-');
    date.append(to_string(year));
    date.append(1, '\n');
    delete[] curr_day_and_month;
    return date;
}

string days_to_date(int days, int year, int month=1, int day=0) {
    int d = day;
    short i;
    for(i = month; (d + num_of_days_in_month(i, year)) < days; i++)
        days += (num_of_days_in_month(i, year));
    
    int days_of_current_month = num_of_days(i, year);
    
    int* curr_day_and_month = decide_day_month(days - d, days_of_current_month, i);
    
    return convert_arr_to_date(curr_day_and_month, year);
}


int main()
{
    int year, day, month;
    read_date(day, month, year);
    cout << "it's been " << how_many_days_since(day, month, year) << " day(s) since " << day << "-" << month << "-" << year << endl;
    cout << "back to date " << days_to_date(15, year, month, day);
    return 0;
}
