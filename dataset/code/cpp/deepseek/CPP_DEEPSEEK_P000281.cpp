#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty()) return "";
    unordered_map<char, int> countT;
    for (char c : t) countT[c]++;
    int left = 0, right = 0;
    int valid = 0;
    int minLen = INT_MAX;
    string minStr = "";
    while (right < s.size()) {
        if (countT.find(s[right]) != countT.end()) {
            if (--countT[s[right]] == 0) valid++;
        }
        while (valid == t.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStr = s.substr(left, minLen);
            }
            if (countT.find(s[left]) != countT.end()) {
                if (countT[s[left]]++ == 0) valid--;
            }
            left++;
        }
        right++;
    }
    return minStr;
}

int main() {
    string s, t;
    cout << "Enter the string s: ";
    cin >> s;
    cout << "Enter the string t: ";
    cin >> t;
    string res = minWindow(s, t);
    cout << "Minimum window substring: " << res << endl;
    return 0;
}