Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solve(unordered_map<char, int> &m1, unordered_map<char, int> &m2, unordered_map<char, int> &m3) {
    for (int i = 0; i < 3; i++) {
        for (char c = 'A'; c <= 'Z'; c++) {
            if (m1[c] == 0 && m2[c] == 0 && m3[c] == 0)
                return false;
        }
        string s1, s2, s3;
        for (int j = 0; j < 3; j++) {
            if (m1[c] == j)
                s1 += c;
            if (m2[c] == j)
                s2 += c;
            if (m3[c] == j)
                s3 += c;
        }
        if (s1.length() != s2.length() || s1.length() != s3.length())
            return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        sort(s3.begin(), s3.end());
        if (s1 != s2 || s1 != s3)
            return false;
    }
    return true;
}

int main() {
    unordered_map<char, int> m1, m2, m3;
    string s;
    for (int i = 0; i < 3; i++) {
        cin >> s;
        for (char c : s) {
            m1[c] = i;
            m2[c] = i;
            m3[c] = i;
        }
    }
    if (solve(m1, m2, m3)) {
        for (char c = 'A'; c <= 'Z'; c++) {
            cout << c << ": " << m1[c] << " " << m2[c] << " " << m3[c] << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

This code reads in three words, and then checks if a solution exists. If it does, it prints out the assignments. If no solution exists, it prints out IMPOSSIBLE. The `solve` function checks if the three words can be assigned to the letters of the equation. It does this by sorting the characters in each word and checking if they are equal. If they are, it increments the count of the letter in the map.