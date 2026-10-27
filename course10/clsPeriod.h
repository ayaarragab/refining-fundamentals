#pragma once
#include "clsString.h"
#include "clsDate.h"

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
    static bool is_overlap(clsPeriod p1, clsPeriod p2)
    {
      return !(p1.to.date1_before_date2(p2.from) || p2.to.date1_before_date2(p1.from));
    }

    bool is_overlap(clsPeriod p2)
    {
      return !(this->to.date1_before_date2(p2.from) || p2.to.date1_before_date2(this->from));
    }

    static int period_in_Days(clsPeriod &p, bool include_current_day = false)
    {
      return p.from.diff_between_dates_positive(p.to, include_current_day);
    }

    int period_in_Days(bool include_current_day = false) {
      return period_in_Days(*this, include_current_day);
    }

    static bool is_date_within_period(clsPeriod p, clsDate d)
    {
      return !((p.from.date1_before_date2(d) && p.to.date1_before_date2(d)) || (p.from.date1_after_date2(d) && p.to.date1_after_date2(d)));
    }

    bool is_date_within_period(clsDate d){
      return is_date_within_period(*this, d);  
    }

    static int count_overlap_days(clsPeriod p1, clsPeriod p2)
    {
      if (!p1.is_overlap(p2))
        return 0;

      int p1_len = period_in_Days(p1);
      int p2_len = period_in_Days(p2);
      int days = 0;

      if (p1_len < p2_len)
      {
        while (p1.from.date1_before_date2(p1.to))
        {
          if (p2.is_date_within_period(p1.from))
            ++days;
          p1.from.increase_date();
        }
      }
  
      if (p2_len < p1_len)
      {
        while (p2.from.date1_before_date2(p2.to))
        {
          if (is_date_within_period(p1, p2.from))
            ++days;
          p2.from.increase_date();
        }
      }
      return days;
    }

    int count_overlap_days(clsPeriod p2) {
      return count_overlap_days(*this, p2);
    }
};