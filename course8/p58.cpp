#include "my_date.h"
using namespace my_date;

int main()
{
    stPeriod p1 = { { 1, 2, 2022 }, { 10, 2, 2022 } };
    stPeriod p2 = { { 5, 2, 2022 }, { 15, 2, 2022 } };

    cout << is_overlap(p1, p2) << endl;
    return 0;
}
