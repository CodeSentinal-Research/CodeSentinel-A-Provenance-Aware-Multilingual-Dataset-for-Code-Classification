#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        ans = max(ans, cnt[s[i] - 'a']);
    }
    cout << ans;
    return 0;
}