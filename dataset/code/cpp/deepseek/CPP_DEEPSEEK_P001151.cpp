#include <iostream>
#include <string>

using namespace std;

string longestPalindromicSubstring(string s) {
    int n = s.length();
    int maxLength = 1;
    int start = 0;

    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && s[j] == s[j+1]) {
            j++;
        }
        int len1 = j - i + 1;
        while(i > 0 && j < n-1 && s[i-1] == s[j+1]) {
            i--;
            j++;
        }
        int len2 = j - i + 1;
        if(len1 > maxLength) {
            maxLength = len1;
            start = i;
        }
        if(len2 > maxLength) {
            maxLength = len2;
            start = i;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromicSubstring(s);
    return 0;
}
This C++ code finds the longest palindromic substring in a given string. It works by expanding the palindromic substring by one character around the center of the string. If the palindromic substring is longer than the longest found, it is saved as the new longest palindromic substring. The time complexity of this solution is O(n^2) due to the use of two nested loops.