#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void partitionHelper(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }
    for (int end = start; end < s.length(); ++end) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(s, 0, current, result);
    
    for (const auto& part : result) {
        for (size_t i = 0; i < part.size(); ++i) {
            if (i > 0) cout << " ";
            cout << part[i];
        }
        cout << endl;
    }
    return 0;
}
