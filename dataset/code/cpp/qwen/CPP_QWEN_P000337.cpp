#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int max_score = 0;
    int zeros = 0, ones = 0;
    for (char c : s) if (c == '0') zeros++; else ones++;
    int curr_zeros = 0, curr_ones = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '0') curr_zeros++;
        else curr_ones++;
        int score = curr_zeros + (ones - curr_ones);
        max_score = max(max_score, score);
    }
    cout << max_score << endl;
    return 0;
}
