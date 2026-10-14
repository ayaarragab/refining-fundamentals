#!/bin/bash
cat > "$1.cpp" << EOF
#include <iostream>
using namespace std;

int main() {
    return 0;
}
EOF

echo "Created ${1}.cpp"
