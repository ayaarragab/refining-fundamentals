#include "my_date.h"
using namespace my_date;

int main()
{
    stPeriod p1 = { { 1, 1, 2022 }, { 5, 1, 2022 } };
    stDate d = { 7, 1, 2022 };
    cout << "Is it within this perios " << is_date_within_period(p1, d) << endl;
    return 0;
}
