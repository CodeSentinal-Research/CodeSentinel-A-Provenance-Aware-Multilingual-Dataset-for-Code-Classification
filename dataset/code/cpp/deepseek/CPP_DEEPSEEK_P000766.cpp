#include <iostream>
#include <string>
using namespace std;

int countWays(string str) {
    if (str.empty())
        return 0;
    int res = 0;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == 'T') {
            int L = 0, R = 0;
            for (int j = i + 1; j < len; j++) {
                if (str[j] == 'T')
                    L++;
                else if (str[j] == 'F')
                    R++;
            }
            if (L == R)
                res += countWays(str.substr(0, i) + 'F' + str.substr(i + 1, len - i - 1));
        }
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << countWays(str);
    return 0;
}

This code defines a function countWays() which counts the number of ways to parenthesize the input string so that it evaluates to True. It iterates over each character in the string, checking if it's 'T', then iterates over the rest of the string to count 'F's. If the number of 'T's and 'F's is the same, it adds the count of the remaining string (after the current character) to the count. This process is recursively performed for each character.