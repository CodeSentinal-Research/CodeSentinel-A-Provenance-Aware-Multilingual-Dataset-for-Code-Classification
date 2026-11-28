#include <iostream>
using namespace std;

int main() {
    string S;
    char C;

    cin >> S >> C;

    for(int i = 0; i < S.size(); i++) {
        if (S[i] == C) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
This program reads a string and a character, then iterates through the string to find the first occurrence of the character. If the character is found, it prints the index of the character. If the character is not found, it prints -1.