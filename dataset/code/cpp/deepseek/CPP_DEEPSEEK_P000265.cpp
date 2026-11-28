#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string S) {
    int n = S.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (S[i] == S[j]) {
                S.erase(j, 1);
                --j;
            }
        }
    }
    return S;
}

int main() {
    string S;
    cout << "Enter a string: ";
    cin >> S;
    S = removeDuplicates(S);
    cout << "String after removing duplicates: " << S << endl;
    return 0;
}
This program reads a string from the user, removes duplicates from it while preserving the original order, and prints the resulting string. It does this by looping through the string, and for each character, it checks the next character to see if it is the same. If it is, it removes the next character and reduces the size of the string by 1. The loop continues until all duplicates are removed.