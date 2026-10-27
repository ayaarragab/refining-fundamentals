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

public:
  clsDate()
  {
    get_system_date();
  };
  clsDate(int day, int month, int year)
  {
    this->_day = day;
    this->_month = month;
    this->_year = year;
  };

  clsDate(string date)
  {
    *(this) = str_to_date(date);
  };

  clsDate(int numOdDaysToAdd, int year) {
    *(this) = clsDate(1, 1, year);
    add_days_to_date(numOdDaysToAdd, *(this));
  }

  ~clsDate();

  int num_of_days_in_month(int month, int year);

  short DayOfWeekOrder(short Day, short Month, short Year)
  {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }

  short DayOfWeekOrder(clsDate &date)
  {
    return DayOfWeekOrder(date._day, date._month, date._year);
  }

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
    int daysInMonths[] = {0, 31, 28 + (is_leap_year(year) ? 1 : 0),
                          31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonths[month];
  }

  string name_of_day(int day)
  {
    string days_names[7] = {"Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday"};
    return days_names[day];
  }

  string name_of_month(int month)
  {
    std::string months[] = {
        "", "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};
    return months[month];
  }

  void read_date(clsDate &date)
  {
    date._year = clsHelper::readNum("Enter the year:\n");
    date._month = clsHelper::readNum("Enter the month:\n");
    date._day = clsHelper::readNum("Enter the day:\n");
  }

  int calculate_day_number(int day, int month, int year)
  {
    double a = (14 - double(month)) / 12;
    double y = year - a;
    double m = month + (12 * a) - 2;
    int d = int(day + y + floor(y / 4) - floor(y / 100) + floor(y / 400) + floor((31 * m) / 12)) % 7;
    return d;
  }

  string MonthShortName(short MonthNumber)
  {
    string Months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};
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

  int how_many_days_sdece(int day, int month, int year)
  {
    int days = 0;
    for (short i = 1; i < month; i++)
      days += (num_of_days_in_month(i, year));
    days += day;
    return days;
  }

  string convert_arr_to_date(clsDate date_struct)
  {
    string date = "";
    date.append(to_string(date_struct._day));
    date.append(1, '-');
    date.append(to_string(date_struct._month));
    date.append(1, '-');
    date.append(to_string(date_struct._year));
    date.append(1, '\n');
    return date;
  }

  void add_days_to_date(int days, clsDate &date)
  {
    int days_to_decrement = days + how_many_days_sdece(date._day, date._month, date._year);
    date._month = 1;
    while (true)
    {
      if (days_to_decrement > num_of_days_in_month(date._month, date._year))
      {
        days_to_decrement -= num_of_days_in_month(date._month, date._year);
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



  bool first_day_in_year(clsDate date)
  {
    return (date._day == 1) && (date._month == 1);
  }

  bool first_day_in_month(clsDate date)
  {
    return date._day == 1;
  }

  void handle_leap_year(clsDate &date);

  void decrease_date(clsDate &date)
  {
    if (first_day_in_year(date))
    {
      date._month = 12;
      date._day = 31;
      --date._year;
    }
    else if (first_day_in_month(date))
    {
      --date._month;
      date._day = num_of_days_in_month(date._month, date._year);
    }
    else
      --date._day;
    handle_leap_year(date);
  }

  void print_date(clsDate date)
  {
    cout << date._day << "-" << date._month << "-" << date._year << endl;
  }

  bool date1_before_date2(clsDate d1, clsDate d2)
  {
    return (d1._year < d2._year) ? true : (d1._year == d2._year && d1._month < d2._month)                     ? true
                                      : (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day) ? true
                                                                                                              : false;
  }

  bool date1_equal_date2(clsDate d1, clsDate d2)
  {
    return ((d1._day == d2._day) && (d1._month == d2._month) && (d1._year == d2._year));
  }

  bool date1_after_date2(clsDate d1, clsDate d2)
  {
    return !(date1_before_date2(d1, d2) || date1_equal_date2(d1, d2));
  }

  bool last_day_in_year(clsDate date)
  {
    return (date._day == 31) && (date._month == 12);
  }

  bool last_day_in_month(clsDate date)
  {
    return date._day == num_of_days_in_month(date._month, date._year);
  }

  void increase_date(clsDate &date)
  {
    if (last_day_in_year(date))
    {
      date._month = 1;
      date._day = 1;
      ++date._year;
    }
    else if (last_day_in_month(date))
    {
      ++date._month;
      date._day = 1;
    }
    else
      ++date._day;
    handle_leap_year(date);
  }

  int diff_between_dates_positive(clsDate d1, clsDate d2, bool include_last_day = false)
  {
    int days = 0;
    while (date1_before_date2(d1, d2))
    {
      increase_date(d1);
      ++days;
    }
    return include_last_day ? days + 1 : days;
  }

  void get_system_date()
  {
    clsDate now;
    time_t t = time(0);
    tm *l_t = localtime(&t);
    this->_day = l_t->tm_mday;
    this->_month = l_t->tm_mon + 1;
    this->_year = l_t->tm_year + 1900;
  }

  void handle_leap_year(clsDate &date)
  {
    if (!is_leap_year(date._year) && date._month == 2 && date._day >= 29)
      date._day = 28;
  }

  bool is_end_of_week(clsDate date)
  {
    if (DayOfWeekOrder(date) == 6)
      return true;
    return false;
  }

  bool is_weekend(clsDate date)
  {
    if (DayOfWeekOrder(date) == 6 || DayOfWeekOrder(date) == 5)
      return true;
    return false;
  }

  bool is_business_day(clsDate date)
  {
    if (!is_weekend(date))
      return true;
    return false;
  }

  int days_untill_end_of_week(clsDate date)
  {
    return 6 - DayOfWeekOrder(date);
  }

  int days_untill_end_of_month(clsDate date)
  {
    return num_of_days_in_month(date._month, date._year) - date._day;
  }

  int days_untill_end_of_year(clsDate date)
  {
    int daysPerYear = is_leap_year(date._year) ? 366 : 365;
    return daysPerYear - how_many_days_sdece(date._day, date._month, date._year);
  }

  int calculate_vacation_days(clsDate &d1, clsDate &d2)
  {
    int days = 0;
    while (date1_before_date2(d1, d2))
    {
      if (is_weekend(d1))
      {
        increase_date(d1);
        continue;
      }
      increase_date(d1);
      ++days;
    }
    return days;
  }

  clsDate add_vacation_days(clsDate &date, int vacation_days)
  {
    while (vacation_days != 0)
    {
      if (is_business_day(date))
        --vacation_days;
      increase_date(date);
    }
    return date;
  }

  int compareDates(clsDate d1, clsDate d2)
  {
    if (date1_before_date2(d1, d2))
      return -1;
    else if (date1_equal_date2(d1, d2))
      return 0;
    else
      return 1;
  }

  bool is_overlap(clsPeriod p1, clsPeriod p2)
  {
    return !(date1_before_date2(p1.to, p2.from) || date1_before_date2(p2.to, p1.from));
  }

  int period_in_Days(clsPeriod &p, bool include_current_day = false)
  {
    return diff_between_dates_positive(p.from, p.to, include_current_day);
  }

  bool is_date_within_period(clsPeriod p, clsDate d)
  {
    return !((date1_before_date2(p.from, d) && date1_before_date2(p.to, d)) || (date1_after_date2(p.from, d) && date1_after_date2(p.to, d)));
  }

  int count_overlap_days(clsPeriod p1, clsPeriod p2)
  {
    if (!is_overlap(p1, p2))
      return 0;

    int p1_len = period_in_Days(p1);
    int p2_len = period_in_Days(p2);
    int days = 0;

    if (p1_len < p2_len)
    {
      while (date1_before_date2(p1.from, p1.to))
      {
        if (is_date_within_period(p2, p1.from))
          ++days;
        increase_date(p1.from);
      }
    }
    if (p2_len < p1_len)
    {
      while (date1_before_date2(p2.from, p2.to))
      {
        if (is_date_within_period(p1, p2.from))
          ++days;
        increase_date(p2.from);
      }
    }
    return days;
  }

  bool is_valid_date(clsDate date)
  {
    return (date._month >= 1 && date._month <= 12) && (date._day >= 1 && date._day <= num_of_days_in_month(date._month, date._year));
  }

  string read_date_string()
  {
    string date;
    cout << "Enter the date:\n";
    getline(cin >> ws, date);
    return date;
  }

  clsDate str_to_date(string date)
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

  string date_to_str(clsDate date)
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
};

class clsPeriod
{
public:
  clsDate from;
  clsDate to;
  clsPeriod(clsDate d1, clsDate d2)
  {
    from = d1;
    to = d2;
  }
};