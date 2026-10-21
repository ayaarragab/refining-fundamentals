#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

namespace my_date
{
    int readNum(string message)
    {
        int n;
        cout << message;
        cin >> n;
        return n;
    }
    struct stDate
    {
        int day;
        int month;
        int year;
    };

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

    short DayOfWeekOrder(stDate &date)
    {
        return DayOfWeekOrder(date.day, date.month, date.year);
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

    void read_date(stDate &date)
    {
        date.year = readNum("Enter the year:\n");
        date.month = readNum("Enter the month:\n");
        date.day = readNum("Enter the day:\n");
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

    string convert_arr_to_date(stDate date_struct)
    {
        string date = "";
        date.append(to_string(date_struct.day));
        date.append(1, '-');
        date.append(to_string(date_struct.month));
        date.append(1, '-');
        date.append(to_string(date_struct.year));
        date.append(1, '\n');
        return date;
    }

    string add_days_to_date(int days, stDate date)
    {
        int days_to_decrement = days + how_many_days_sdece(date.day, date.month, date.year);
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
            }
            else
            {
                date.day = days_to_decrement;
                break;
            }
        }
        return convert_arr_to_date(date);
    }

    bool first_day_in_year(stDate date)
    {
        return (date.day == 1) && (date.month == 1);
    }

    bool first_day_in_month(stDate date)
    {
        return date.day == 1;
    }

    void handle_leap_year(stDate &date);

    void decrease_date(stDate &date)
    {
        if (first_day_in_year(date))
        {
            date.month = 12;
            date.day = 31;
            --date.year;
        }
        else if (first_day_in_month(date))
        {
            --date.month;
            date.day = num_of_days_in_month(date.month, date.year);
        }
        else
            --date.day;
        handle_leap_year(date);
    }

    void print_date(stDate date)
    {
        cout << date.day << "-" << date.month << "-" << date.year << endl;
    }

    bool date1_before_date2(stDate d1, stDate d2)
    {
        return (d1.year < d2.year) ? true : (d1.year == d2.year && d1.month < d2.month)                   ? true
                                        : (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) ? true
                                                                                                          : false;
    }

    bool date1_equal_date2(stDate d1, stDate d2)
    {
        return ((d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year));
    }

    bool date1_after_date2(stDate d1, stDate d2)
    {
        return !(date1_before_date2(d1, d2) || date1_equal_date2(d1, d2));
    }

    bool last_day_in_year(stDate date)
    {
        return (date.day == 31) && (date.month == 12);
    }

    bool last_day_in_month(stDate date)
    {
        return date.day == num_of_days_in_month(date.month, date.year);
    }

    void increase_date(stDate &date)
    {
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
        handle_leap_year(date);
    }

    int diff_between_dates_positive(stDate d1, stDate d2, bool include_last_day = false)
    {
        int days = 0;
        while (date1_before_date2(d1, d2))
        {
            increase_date(d1);
            ++days;
        }
        return include_last_day ? days + 1 : days;
    }

    stDate get_system_date()
    {
        stDate now;
        time_t t = time(0);
        tm *l_t = localtime(&t);
        now.day = l_t->tm_mday;
        now.month = l_t->tm_mon + 1;
        now.year = l_t->tm_year + 1900;

        return now;
    }

    void handle_leap_year(stDate &date)
    {
        if (!is_leap_year(date.year) && date.month == 2 && date.day >= 29)
            date.day = 28;
    }

    bool is_end_of_week(stDate date)
    {
        if (DayOfWeekOrder(date) == 6)
            return true;
        return false;
    }

    bool is_weekend(stDate date)
    {
        if (DayOfWeekOrder(date) == 6 || DayOfWeekOrder(date) == 5)
            return true;
        return false;
    }

    bool is_business_day(stDate date)
    {
        if (!is_weekend(date))
            return true;
        return false;
    }

    int days_untill_end_of_week(stDate date)
    {
        return 6 - DayOfWeekOrder(date);
    }

    int days_untill_end_of_month(stDate date)
    {
        return num_of_days_in_month(date.month, date.year) - date.day;
    }

    int days_untill_end_of_year(stDate date)
    {
        int daysPerYear = is_leap_year(date.year) ? 366 : 365;
        return daysPerYear - how_many_days_sdece(date.day, date.month, date.year);
    }

    int calculate_vacation_days(stDate &d1, stDate &d2)
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

    stDate add_vacation_days(stDate &date, int vacation_days)
    {
        while (vacation_days != 0)
        {
            if (is_business_day(date))
                --vacation_days;
            increase_date(date);
        }
        return date;
    }

    int compareDates(stDate d1, stDate d2)
    {
        if (date1_before_date2(d1, d2))
            return -1;
        else if (date1_equal_date2(d1, d2))
            return 0;
        else
            return 1;
    }

    struct stPeriod
    {
        stDate from;
        stDate to;
    };

    bool is_overlap(stPeriod p1, stPeriod p2) {
        return !(date1_before_date2(p1.to, p2.from) || date1_before_date2(p2.to, p1.from));
    }
    
    int period_in_Days(stPeriod &p, bool include_current_day=false) {
        return diff_between_dates_positive(p.from, p.to, include_current_day);
    }

    bool is_date_within_period(stPeriod p, stDate d) {
        return !((date1_before_date2(p.from, d) && date1_before_date2(p.to, d)) || (date1_after_date2(p.from, d) && date1_after_date2(p.to, d)));
    }

    int count_overlap_days(stPeriod p1, stPeriod p2) {
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
} // namespace name
