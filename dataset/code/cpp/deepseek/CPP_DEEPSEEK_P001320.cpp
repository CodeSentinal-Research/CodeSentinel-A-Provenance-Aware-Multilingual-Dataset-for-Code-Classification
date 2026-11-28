#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateParentheses(int n, int open, int close, string str, vector<string> &res) {
    if (open == n && close == n) {
        res.push_back(str);
        return;
    }
    if (open < n) {
        generateParentheses(n, open + 1, close, str + "(", res);
    }
    if (close < open) {
        generateParentheses(n, open, close + 1, str + ")", res);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> res;
    generateParentheses(n, 0, 0, "", res);
    sort(res.begin(), res.end());
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}