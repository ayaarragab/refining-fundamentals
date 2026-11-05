#include <bits/stdc++.h>
using namespace std;
 
long long nCr(int n, int r, int i = 1, long long res = 1) {
    
    if (r == 0 || (n == r))
        return 1;
    
    if (i > r)
      return res;
    
    
    return nCr(n, r, i + 1, res * (n - r + i) / i);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r;
    
    cin >> n;
    cin >> r;
    
    cout << nCr(n, r) << "\n";
    return 0;
}