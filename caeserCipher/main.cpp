#include <iostream>
#include <string>
using namespace std;


int main() {
    string text;
    int offset;

    cout << "Type text:" << endl;
    getline(cin, text);

    string generated = text;

    cout << "Type offset:" << endl;
    cin >> offset;

    if (0 > offset or offset > 26) {
        cout << "Incorrect offset!" << endl;
    }

    for (int i = 0; i < text.length(); i++) {
        int ch = (unsigned char) text[i];

        if (ch >= 97 and ch <= 122) {
            // Edit lowercase letters
            ch = (((ch - 97) + offset) % 26) + 97;
            ch -= 97;
            ch += offset;
            ch %= 26;
            ch += 97;
        } else if (ch >= 65 and ch <= 90) {
            // Edit uppercase letters
            ch = (((ch - 65) + offset) % 26) + 65;
        }
        // Other symbols will not be changed

        generated[i] = ch;
    }

    for (char c : generated) {
        cout << c;
    }
}

