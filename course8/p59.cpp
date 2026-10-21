#include "my_date.h"
using namespace my_date;

int main()
{
    stPeriod p1 = { { 1, 1, 2022 }, { 5, 1, 2022 } };
    int p_days = period_in_Days(p1, true);
    cout << p_days << endl;
    return 0;
}
