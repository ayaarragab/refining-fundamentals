#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(string s, int idx) {    
    if (idx == s.length())
        return 0;
    if (isVowel(tolower(s[idx])))
        return 1 + countVowels(s, idx + 1);
    return countVowels(s, idx + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << countVowels(s, 0) << "\n";
    return 0;
}
