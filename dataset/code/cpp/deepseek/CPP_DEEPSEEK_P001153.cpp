#include <iostream>
#include <string>
using namespace std;

int countPalindromicSubstrings(string s) {
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool flag = true;

            for (int k = 0; k <= (j - i); k++ {
                if (s[i + k] != s[j - k]) {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    cout << countPalindromicSubstrings(s);

    return 0;
}