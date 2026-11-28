Here is the code:

#include <iostream>
#include <string>
using namespace std;

string string_compression(string S) {
    string compressed = "";
    int count = 1;
    for (int i = 1; i < S.length(); i++) {
        if (S[i] == S[i - 1]) {
            count++;
        } else {
            compressed += S[i - 1] + to_string(count);
            count = 1;
        }
    }
    compressed += S[S.length() - 1] + to_string(count);
    return compressed.length() < S.length() ? compressed : S;
}

int main() {
    string S;
    cout << "Enter a string: ";
    cin >> S;
    string compressed = string_compression(S);
    cout << "Compressed string: " << compressed << endl;
    return 0;
}
This program will ask the user for a string, then compress it using the string compression technique. The result is then printed out.