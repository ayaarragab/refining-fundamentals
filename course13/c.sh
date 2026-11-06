#!/bin/bash
cat > "$1.cpp" << EOF
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
EOF

echo "Created ${1}.cpp"