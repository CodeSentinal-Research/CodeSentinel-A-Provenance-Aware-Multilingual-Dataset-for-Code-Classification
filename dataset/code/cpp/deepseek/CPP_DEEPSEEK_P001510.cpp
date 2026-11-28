#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    unordered_map<char, int> m;
    int start = 0, ans = 0;
    for(int end = 0; end < s.size(); end++) {
        m[s[end]]++;
        while(m[s[end]] > 1 || (end - start + 1 - m.size()) > k) {
            m[s[start]]--;
            start++;
        }
        ans = max(ans, end - start + 1);
    }
    cout << ans << endl;
    return 0;
}