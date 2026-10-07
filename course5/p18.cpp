#include <iostream>
using namespace std;

string read_string(string message) {
    string str;
    cout << message;
    // cin.ignore(1, '\n');
    getline(cin, str);
    return str;
}

string encrypt(string str, short key) {
    string encrypted = "";
    for (short i = 0; i < str.length(); i++)
    {
        char c = char(str[i]) + key;
        encrypted.append(1, c);
    }
    return encrypted;
}

string decrypt(string encrypted, short key) {
    string decrypted = "";
    for (short i = 0; i < encrypted.length(); i++)
    {
        char c = char(encrypted[i]) - key;
        decrypted.append(1, c);
    }
    return decrypted;
}

int main() {
    string name = read_string("Enter your name: \n");
    cout << "Encrypted: " << encrypt(name, 2) << "\n";
    cout << "Decrypted: " << decrypt(encrypt(name, 2), 2) << "\n";
    return 0;
}
