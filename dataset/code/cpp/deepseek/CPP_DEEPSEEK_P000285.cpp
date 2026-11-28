#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int j = 0;
    for (int i = 0; i < s1.length() && j < s2.length(); i++) {
        if (s1[i] == s2[j])
            j++;
    }

    if (j == s2.length())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}