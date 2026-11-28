#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

void solve(string str, int index, vector<string>& ans) {
    if (index == str.length()) {
        ans.push_back(str);
        return;
    }
    for (int i = index; i < str.length(); i++) {
        string part = str.substr(index, i - index + 1);
        if (isPalindrome(part)) {
            solve(str, i + 1, ans);
        }
    }
}

int main() {
    string str;
    cin >> str;
    vector<string> ans;
    solve(str, 0, ans);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}