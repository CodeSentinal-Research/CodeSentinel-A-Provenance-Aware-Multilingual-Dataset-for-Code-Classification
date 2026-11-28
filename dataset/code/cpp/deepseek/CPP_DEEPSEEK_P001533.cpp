#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    unordered_map<char, int> charIndex;
    deque<int> dq;
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < s.size(); i++) {
        if (charIndex.find(s[i]) == charIndex.end()) {
            charIndex[s[i]] = i;
            dq.push_back(i);
            if (dq.size() == k) {
                start = dq.front();
                dq.pop_front();
            }
        } else {
            dq.erase(remove(dq.begin(), dq.end(), charIndex[s[i]]), dq.end());
            charIndex[s[i]] = i;
            dq.push_back(i);
            if (dq.size() == k) {
                start = dq.front();
                dq.pop_front();
            }
        }
        maxLen = max(maxLen, (int)dq.size());
    }

    cout << maxLen;

    return 0;
}