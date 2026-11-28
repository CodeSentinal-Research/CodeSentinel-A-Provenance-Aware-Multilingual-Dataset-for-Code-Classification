Here is the C++ code that you can use:

#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cout << "Enter a string: ";
    cin >> S;

    int count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ' ') {
            count++;
        }
    }

    cout << "Number of segments: " << count << endl;

    return 0;
}

This program will take a string input from the user, count the number of non-space characters in it and print the number of segments.