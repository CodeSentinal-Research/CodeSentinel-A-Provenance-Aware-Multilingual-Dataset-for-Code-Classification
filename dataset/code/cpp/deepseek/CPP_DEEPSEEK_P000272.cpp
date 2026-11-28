#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
        return "";

    for (int i = 0; i < strs[0].size(); ++i) {
        for (const string &str : strs) {
            if (i >= str.size() || str[i] != strs[0][i])
                return str.substr(0, i);
        }
    }
    return strs[0];
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> strs;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        strs.push_back(s);
    }

    cout << longestCommonPrefix(strs);

    return 0;
}