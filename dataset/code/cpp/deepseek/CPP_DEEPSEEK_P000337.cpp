#include <iostream>
#include <vector>

using namespace std;

int maxScore(string s) {
    int maxZero = 0, maxOne = 0, max2zero = 0, max2one = 0;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            maxZero++;
            max2zero++;
        } else {
            maxOne++;
            max2one++;
        }
    }

    return max(max0 + max2zero, max1 + max2one);
}

int main() {
    string s;
    cin >> s;
    cout << maxScore(s);
    return 0;
}
This program calculates the maximum score by splitting a binary string into two non-empty parts. The score is calculated by finding the maximum number of '0's and '1's in the string, and then choosing the maximum score out of the two possible scores after splitting the string into two parts.