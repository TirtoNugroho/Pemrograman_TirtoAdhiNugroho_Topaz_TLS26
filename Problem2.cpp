#include <iostream>

using namespace std;

int charToHuruf(char ch) {
    if (ch >= 'a') return ch - 'a' + 1;
    else return ch - 'A' + 1;
}

char hurufToChar(int huruf, bool lowercase) {
    if (lowercase) {
        return huruf + 'a' - 1;
    } else {
        return huruf + 'A' - 1;
    }
}

int main() {
    string pesan;
    cin >> pesan;

    string sandi = "";
    int prevChar = 0;

    for (size_t i = 0; i < pesan.length(); ++i) {
        int ch = charToHuruf(pesan[i]);
        ch += prevChar;

        if (ch > 26) {
            ch = ch % 26;
        }

        sandi += hurufToChar(ch, pesan[i] >= 'a');
        prevChar = charToHuruf(pesan[i]);
    }

    cout << sandi << endl;

    return 0;
}
