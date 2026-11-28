#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minStickers(vector<string> &stickers, string target) {
    unordered_map<char, int> cnt;
    for (char c : target) cnt[c]++;

    function<int(string)> dp = [&](string s) {
        if (s.empty()) return 0;
        int &res = memo[s];
        if (res != -1) return res;
        res = cnt[s[0]] + 1;
        for (string &sticker : stickers) {
            if (s.find(sticker) != string::npos) {
                res = min(res, dp(s.replace(s.find(sticker), sticker.size(), sticker)));
            }
        }
        return res;
    };

    vector<string> stickers2;
    for (string &sticker : stickers) sort(sticker.begin(), sticker.end());
    for (int i = 0; i < stickers.size(); ++i) {
        for (int j = i + 1; j < stickers.size(); ++j) {
            if (stickers[i].find(stickers[j]) != string::npos) {
                stickers2.push_back(stickers[j]);
                break;
            }
        }
    }

    for (char c : target) cnt[c]--;
    int ans = dp(target);
    for (char c : target) {
        if (cnt[c] > 0) return -1;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<string> stickers(N);
    for (int i = 0; i < N; ++i) {
        cin >> stickers[i];
    }
    string target;
    cin >> target;
    cout << minStickers(stickers, target);
    return 0;
}