#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int minStickers(vector<string>& stickers, string target, vector<int>& memo) {
    if (target.empty()) return 0;
    
    // Create key from target
    string key = target;
    sort(key.begin(), key.end());
    // Use map for memoization instead of vector for simplicity
    static map<string, int> memoMap;
    if (memoMap.find(key) != memoMap.end()) return memoMap[key];
    
    int minUsed = INT_MAX;
    for (const string& sticker : stickers) {
        vector<int> stickerCount(26, 0);
        for (char c : sticker) stickerCount[c-'a']++;
        
        string remaining = "";
        vector<int> targetCount(26, 0);
        for (char c : target) targetCount[c-'a']++;
        
        for (int i = 0; i < 26; ++i) {
            if (targetCount[i] > stickerCount[i]) {
                for (int j = 0; j < targetCount[i] - stickerCount[i]; ++j) {
                    remaining += (char)('a' + i);
                }
            }
        }
        
        if (remaining.length() < target.length()) {
            int res = minStickers(stickers, remaining, memo);
            if (res != -1) {
                minUsed = min(minUsed, 1 + res);
            }
        }
    }
    
    memoMap[key] = (minUsed == INT_MAX) ? -1 : minUsed;
    return memoMap[key];
}

int main() {
    int n;
    cin >> n;
    vector<string> stickers(n);
    for (int i = 0; i < n; ++i) cin >> stickers[i];
    
    string target;
    cin >> target;
    
    vector<int> memo;
    cout << minStickers(stickers, target, memo) << endl;
    return 0;
}
