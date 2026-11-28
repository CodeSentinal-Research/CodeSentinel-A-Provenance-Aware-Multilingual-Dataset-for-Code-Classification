#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

int lengthOfLongestSubstring(string s, int k) {
    unordered_map<char, int> position;
    deque<char> dq;
    int res = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (position.find(s[i]) != position.end()) {
            while (dq.front() != s[position[s[i]]]) {
                position.erase(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
        dq.push_back(s[i]);
        position[s[i]] = i;
        res = max(res, (int)dq.size());
        if (dq.size() > k) {
            position.erase(dq.front());
            dq.pop_front();
       
        }
    }
    return res;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << lengthOfLongestSubstring(s, k);
    return 0;
}