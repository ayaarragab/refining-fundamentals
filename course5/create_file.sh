#!/bin/bash
cat > "p$1.cpp" << EOF
#include <iostream>
using namespace std;

int readNum() {
    int n;
    cout << "Enter a number\n";
    cin >> n;
    return n;
}

int main() {
    return 0;
}
EOF

echo "Created p${1}.cpp"