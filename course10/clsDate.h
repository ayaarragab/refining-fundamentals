#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "clsHelper.h"
#include "clsString.h"
using namespace std;

class clsDate
{
private:
  short _day;
  short _month;
  short _year;

  int _num_of_days(int month, int year)
  {
    return _num_of_days_in_month(month, year);
  }

  int _num_of_hours(int month, int year)
  {
    return _num_of_days(month, year) * 24;
  }

  int _num_of_minutes(int month, int year)
  {
    return _num_of_hours(month, year) * 60;
  }

  int num_of_seconds(int month, int year)
  {
    return _num_of_minutes(month, year) * 60;
  }

  static int _num_of_days_in_month(int month, int year)
  {
    int daysInMonths[] = {0, 31, 28 + (is_leap_year(year) ? 1 : 0),
                          31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonths[month];
  }

  int _num_of_days_in_month()
  {
    return _num_of_days_in_month(_month, _year);
  }

  static string _name_of_day(int day)
  {
    string days_names[7] = {"Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday"};
    return days_names[day];
  }

  string _name_of_day()
  {
    return _name_of_day(_day);
  }

  static string _name_of_month(int month)
  {
    std::string months[] = {
        "", "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};
    return months[month];
  }

  string _name_of_month() {
    return _name_of_month(_month);
  }

  int _calculate_day_number(int day, int month, int year)
  {
    double a = (14 - double(month)) / 12;
    double y = year - a;
    double m = month + (12 * a) - 2;
    int d = int(day + y + floor(y / 4) - floor(y / 100) + floor(y / 400) + floor((31 * m) / 12)) % 7;
    return d;
  }

  string _MonthShortName(short MonthNumber)
  {
    string Months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};
    return (Months[MonthNumber - 1]);
  }

  static clsDate _get_system_date()
  {
    clsDate now;
    time_t t = time(0);
    tm *l_t = localtime(&t);
    now._day = l_t->tm_mday;
    now._month = l_t->tm_mon + 1;
    now._year = l_t->tm_year + 1900;

    return now;
  }

  void _set_to_system_date()
  {
    *(this) = _get_system_date();
  }

public:
  clsDate()
  {
    _set_to_system_date();
  };
  
  clsDate(int day, int month, int year)
  {
    this->_day = day;
    this->_month = month;
    this->_year = year;
  };

  clsDate(string day, string month, string year)
  {
    this->_day = stoi(day);
    this->_month = stoi(month);
    this->_year = stoi(year);
  };

  clsDate(string date)
  {
    *(this) = str_to_date(date);
  };

  clsDate(int numOdDaysToAdd, int year)
  {
    *(this) = clsDate(1, 1, year);
    add_days_to_date(numOdDaysToAdd, *(this));
  }

  static short DayOfWeekOrder(short Day, short Month, short Year)
  {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }

  static short DayOfWeekOrder(clsDate &date)
  {
    return DayOfWeekOrder(date._day, date._month, date._year);
  }

  short DayOfWeekOrder()
  {
    return DayOfWeekOrder(*this);
  }

  static bool is_leap_year(int year)
  {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }

  bool is_leap_year()
  {
    return is_leap_year(this->_year);
  }

  static void read_date(clsDate &date)
  {
    date._year = clsHelper::readNum("Enter the year:\n");
    date._month = clsHelper::readNum("Enter the month:\n");
    date._day = clsHelper::readNum("Enter the day:\n");
  }



  void PrintMonthCalendar(short Month, short Year)
  {
    int NumberOfDays;
    // Index of the day from 0 to 6
    int current = _calculate_day_number(1, Month, Year);
    NumberOfDays = _num_of_days_in_month(Month, Year);
    // Print the current month name
    printf("\n _______________%s_______________\n\n",
           _MonthShortName(Month).c_str());
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

  int how_many_days_since(int day, int month, int year)
  {
    int days = 0;
    for (short i = 1; i < month; i++)
      days += (_num_of_days_in_month(i, year));
    days += day;
    return days;
  }

  int how_many_days_since()
  {
    return how_many_days_since(this->_day, this->_month, this->_year);
  }

  string date_to_string()
  {
    string date = "";
    date.append(to_string(this->_day));
    date.append(1, '-');
    date.append(to_string(this->_month));
    date.append(1, '-');
    date.append(to_string(this->_year));
    date.append(1, '\n');
    return date;
  }

  void add_days_to_date(int days, clsDate &date)
  {
    int days_to_decrement = days + how_many_days_since(date._day, date._month, date._year);
    date._month = 1;
    while (true)
    {
      if (days_to_decrement > _num_of_days_in_month(date._month, date._year))
      {
        days_to_decrement -= _num_of_days_in_month(date._month, date._year);
        ++date._month;
        if (date._month > 12)
        {
          date._month = 1;
          ++date._year;
        }
      }
      else
      {
        date._day = days_to_decrement;
        break;
      }
    }
  }

  bool first_day_in_year()
  {
    return (this->_day == 1) && (_month == 1);
  }

  bool first_day_in_month()
  {
    return _day == 1;
  }

  void decrease_date()
  {
    if (this->first_day_in_year())
    {
      _month = 12;
      _day = 31;
      --_year;
    }
    else if (this->first_day_in_month())
    {
      --_month;
      _day = _num_of_days_in_month(_month, _year);
    }
    else
      --_day;
    handle_leap_year((*this));
  }

  void print_date()
  {
    cout << _day << "-" << _month << "-" << _year << endl;
  }

  bool date1_before_date2(clsDate d2)
  {
    return (_year < d2._year) ? true : (_year == d2._year && _month < d2._month)                     ? true
                                      : (_year == d2._year && _month == d2._month && _day < d2._day) ? true
                                                                                                              : false;
  }

  static bool date1_equal_date2(clsDate d1, clsDate d2)
  {
    return ((d1._day == d2._day) && (d1._month == d2._month) && (d1._year == d2._year));
  }

  bool date1_equal_date2(clsDate d2) {
    return date1_equal_date2(*this, d2);
  }

  bool date1_after_date2(clsDate d2)
  {
    return !(date1_before_date2(d2) || date1_equal_date2(d2));
  }


  bool last_day_in_year()
  {
    return (_day == 31) && (_month == 12);
  }

  bool last_day_in_month()
  {
    return _day == _num_of_days_in_month(_month, _year);
  }

  void increase_date()
  {
    if (last_day_in_year())
    {
      _month = 1;
      _day = 1;
      ++_year;
    }
    else if (last_day_in_month())
    {
      ++_month;
      _day = 1;
    }
    else
      ++_day;
    handle_leap_year();
  }

  static int diff_between_dates_positive(clsDate d1, clsDate d2, bool include_last_day = false)
  {
    int days = 0;
    while (d1.date1_before_date2(d2))
    {
      d1.increase_date();
      ++days;
    }
    return include_last_day ? days + 1 : days;
  }

  int diff_between_dates_positive(clsDate d2, bool include_last_day = false) {
    return diff_between_dates_positive(*this, d2, include_last_day);
  }

  static void handle_leap_year(clsDate &date)
  {
    if (!is_leap_year(date._year) && date._month == 2 && date._day >= 29)
      date._day = 28;
  }

  void handle_leap_year()
  {
    handle_leap_year(*this);
  }

  static clsDate now() {
    return _get_system_date();
  }

  static bool is_end_of_week(clsDate date)
  {
    if (DayOfWeekOrder(date) == 6)
      return true;
    return false;
  }

  bool is_end_of_week() {
    return is_end_of_week(*this);
  }

  static bool is_weekend(clsDate date)
  {
    if (DayOfWeekOrder(date) == 6 || DayOfWeekOrder(date) == 5)
      return true;
    return false;
  }

  bool is_weekend() {
    return is_end_of_week(*this);
  }

  static bool is_business_day(clsDate date)
  {
    if (!is_weekend(date))
      return true;
    return false;
  }

  bool is_business_day() {
    return is_business_day(*this);
  }

  static int days_untill_end_of_week(clsDate date)
  {
    return 6 - DayOfWeekOrder(date);
  }

  int days_untill_end_of_week() {
    return days_untill_end_of_week(*this);
  }

  static int days_untill_end_of_month(clsDate date)
  {
    return date._num_of_days_in_month() - date._day;
  }

  int days_untill_end_of_month() {
    return days_untill_end_of_month(*this);
  }

  int days_untill_end_of_year(clsDate date)
  {
    int daysPerYear = is_leap_year(date._year) ? 366 : 365;
    return daysPerYear - how_many_days_since(date._day, date._month, date._year);
  }

  int calculate_vacation_days(clsDate &d2)
  {
    int days = 0;
    while (this->date1_before_date2(d2))
    {
      if (this->is_weekend(d2))
      {
        this->increase_date();
        continue;
      }
      this->increase_date();
      ++days;
    }
    return days;
  }

  static clsDate add_vacation_days(clsDate &date, int vacation_days)
  {
    while (vacation_days != 0)
    {
      if (is_business_day(date))
        --vacation_days;
      date.increase_date();
    }
    return date;
  }

  clsDate add_vacation_days(int vacation_days)
  {
    return add_vacation_days(*this, vacation_days);
  }

  static int compareDates(clsDate d1, clsDate d2)
  {
    if (d1.date1_before_date2(d2))
      return -1;
    else if (d1.date1_equal_date2(d2))
      return 0;
    else
      return 1;
  }

  int compareDates(clsDate d2) {
    return compareDates(*this, d2);
  }

  static bool is_valid_date(clsDate date)
  {
    return (date._month >= 1 && date._month <= 12) && (date._day >= 1 && date._day <= _num_of_days_in_month(date._month, date._year));
  }

  bool is_valid_date() {
    return is_valid_date(*this);
  }

  static string read_date_string()
  {
    string date;
    cout << "Enter the date:\n";
    getline(cin >> ws, date);
    return date;
  }

  static clsDate str_to_date(string date)
  {
    vector<string> vec;
    clsDate d;
    short i;
    for (i = 0; i < date.length(); i++)
    {
      if (date[i] == '/')
      {
        vec.push_back(date.substr(0, i));
        date.erase(0, i + 1);
        i = 0;
      }
    }
    if (date != "")
    {
      vec.push_back(date);
    }
    d._day = stoi(vec[0]);
    d._month = stoi(vec[1]);
    d._year = stoi(vec[2]);
    return d;
  }

  static string date_to_str(clsDate date)
  {
    return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
  }

  static string formatDate(clsDate date, string format = "dd/mm/yyyy")
  {
    string new_date;
    new_date = clsString::replace_word(format, "dd", to_string(date._day));
    new_date = clsString::replace_word(new_date, "mm", to_string(date._month));
    new_date = clsString::replace_word(new_date, "yyyy", to_string(date._year));
    return new_date;
  }

  string date_to_str() {
    return date_to_str(*this);
  }
};
