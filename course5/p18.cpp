#include <iostream>
using namespace std;

string read_string(string message) {
    string str;
    cout << message;
    // cin.ignore(1, '\n');
    getline(cin, str);
    return str;
}

string encrypt(string str) {
    string encrypted = "";
    for (short i = 0; i < str.length(); i++)
    {
        char c = char(str[i]) + 2;
        encrypted.append(1, c);
    }
    return encrypted;
}

string decrypt(string encrypted) {
    string decrypted = "";
    for (short i = 0; i < encrypted.length(); i++)
    {
        char c = char(encrypted[i]) - 2;
        decrypted.append(1, c);
    }
    return decrypted;
}

int main() {
    string name = read_string("Enter your name: \n");
    cout << "Encrypted: " << encrypt(name) << "\n";
    cout << "Decrypted: " << decrypt(encrypt(name)) << "\n";
    return 0;
}
