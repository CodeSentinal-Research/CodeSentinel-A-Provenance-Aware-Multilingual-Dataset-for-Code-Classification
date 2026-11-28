#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cout << "Enter a string: ";
    cin >> S;

    for (int i = 1; i < S.length(); i++) {
        if (isdigit(S[i])) {
            int digit = S[i] - '0';
            digit = (digit + 1) % 10;
            S[i] = digit + '0';
        }
    }

    cout << "Modified string: " << S << endl;

    return 0;
}