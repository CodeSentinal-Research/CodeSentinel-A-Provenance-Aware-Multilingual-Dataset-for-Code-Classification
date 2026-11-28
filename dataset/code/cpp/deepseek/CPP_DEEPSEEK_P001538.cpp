#include <iostream>
#include <string>
using namespace std;

bool checkInSubString(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == m) 
            return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (checkInSubString(s1, s2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}