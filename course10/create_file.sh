#!/bin/bash
cat > "p$1.cpp" << EOF
#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

int main() {
    return 0;
}
EOF

echo "Created p${1}.cpp"