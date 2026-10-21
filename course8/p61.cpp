#include "my_date.h"
using namespace my_date;

int main()
{
    stPeriod p1 = { { 1, 1, 2022 }, { 10, 1, 2022 } };
    stPeriod p2 = { { 5, 1, 2022 }, { 30, 12, 2050 } };

    cout << "Number of overlapping days is " << count_overlap_days(p1, p2) << endl;
    return 0;
}
