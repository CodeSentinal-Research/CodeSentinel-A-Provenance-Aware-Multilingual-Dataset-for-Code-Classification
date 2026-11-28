Here is the C++ code for the problem:

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> m;
    for (char c : t) m[c]++;

    int l = 0, r = 0;
    int count = m.size(); 
    string res = "";

    while (r < s.size()) {
        if (m.count(s[r])) {
            m[s[r]]--;
            if (m[s[r]] == 0) count--;
        }
        r++;

        while (count == 0) {
            if (r - l + 1 > res.size()) res = s.substr(l, r - l + 1);

            if (m.count(s[l])) {
                m[s[l]]++;
                if (m[s[l]] == 1) count++;
            }
            l++;
        }
    }

    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    string res = minWindow(s, t);
    cout << res << endl;
    return 0;
}

This code uses a sliding window approach to solve the problem. The window contains all the characters from T in S. The left and right pointers move through S, and if a character in S is in T, the count of this character in T decreases. If the count of all characters in T is 0, it means the window contains all characters from T, and the size of the window is updated if necessary.