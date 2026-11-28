#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> last(26, -1);
    for (int i = 0; i < s.length(); ++i) {
        last[s[i] - 'a'] = i;
    }

    int start = 0, end = 0;
    vector<int> ans;

    for (int i = 0; i < s.length(); ++i) {
        end = max(end, last[s[i] - 'a']);
        if (end == i) {
            ans.push_back(end - start + 1);
            start = end + 1;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}