#include <bits/stdc++.h>
using namespace std;

void Knapsack(int n, int cap, int *values, int *weights, int &max_value, int i = 0) {
    if (i == n)
        return;
    int curr_sum_values = values[i], curr_weight = weights[i];

    for (short k = 0; k < n; k++)
    {
        if (k != i)
        {
            curr_sum_values += values[k];
            curr_weight += weights[k];
            if (curr_weight <= cap)
                max_value = max_value < curr_sum_values ? curr_sum_values : max_value;
        }
    }
    Knapsack(n, cap, values, weights, max_value, i + 1);  
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cap, max_value = 0;
    cin >> n;
    cin >> cap;
    int i = 0;
    int *weights = new int[n];
    int *values = new int[n];
    while (i != n)
    {
        int w, v;
        cin >> w;
        cin >> v;
        weights[i] = w;
        values[i] = v;
        ++i;
    }
    Knapsack(n, cap, values, weights, max_value);
    cout << max_value << "\n";    
    return 0;
}
