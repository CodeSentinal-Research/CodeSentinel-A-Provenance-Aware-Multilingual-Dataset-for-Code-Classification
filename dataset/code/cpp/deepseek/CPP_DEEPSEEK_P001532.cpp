#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

int longestSubstringWithKDistinct(string str, int k) {
    unordered_map<char, int> ump;
    deque<int> dq;
    int i, j, maxLen = 0, currMaxLen = 0;
    for(i = 0; i < str.length(); ++i) {
        if(ump.find(str[i]) == ump.end()) {
            if(dq.size() == k) {
                ump.erase(str[dq.front()]);
                dq.pop_front();
            }
            dq.push_back(i);
            ump[str[i]] = i;
            currMaxLen = max(currMaxLen, (int)dq.size());
        } else {
            dq.erase(ump[str[i]]);
            dq.push_back(ump[str[i]]);
            ump[str[i]] = i;
       
        }
        maxLen = max(maxLen, currMaxLen);
    }
    return maxLen;
}

int main() {
    string str;
    int k;
    cin >> str >> k;
    cout << longestSubstringWithKDistinct(str, k);
    return 0;
}