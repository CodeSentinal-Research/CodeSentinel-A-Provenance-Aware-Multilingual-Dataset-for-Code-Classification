Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPS(string str) {
    int n = str.size();

    int lookup[n+2][n+2];
    memset(lookup, 0, sizeof(lookup));

    for(int i=0; i<=n; i++) {
        lookup[i][i] = 1;
        if (i < n)
            lookup[i][i+1] = 2;
    }

    for(int len=3; len<=n+1; len++) {
        for(int i=0; i<=n-len+1; i++) {
            int j = i+len-1;
            if (str[i] == str[j] && len == 2)
                lookup[i][j] = 3;
            else if (str[i] == str[j])
                lookup[i][j] = lookup[i+1][j-1] * 2;
            else
                lookup[i][j] = lookup[i][j-1] + lookup[i+1][j] - lookup[i+1][j-1];
        }
    }

    return lookup[0][n];
}

int main() {
    string str;
    cin >> str;
    cout << countPS(str);
    return 0;
}

This program calculates the number of palindromic subsequences in a string using dynamic programming. It first creates a 2D lookup table to store the results of the subproblems. The lookup table is initialized with zeros. Then it fills the lookup table in a bottom-up manner. The final result is the value in the top-right corner of the lookup table.