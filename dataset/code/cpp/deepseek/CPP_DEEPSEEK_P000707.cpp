Here is a C++ code snippet that generates all combinations of balanced parentheses using recursion:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateParentheses(int n, int m, vector<char> &s, vector<string> &ans) {
    if (m == 0 && n == 0) {
        string t;
        for (char c: s) {
            t += c;
        }
        ans.push_back(t);
        return;
    }
    if (n > 0) {
        s.push_back('(');
        generateParentheses(n - 1, m + 1, s, ans);
        s.pop_back();
    }
    if (m > 0) {
        s.push_back(')');
        generateParentheses(n, m - 1, s, ans);
        s.pop_back();
    }
}

int main() {
    int N;
    cin >> N;
    vector<char> s;
    vector<string> ans;
    generateParentheses(N, 0, s, ans);
    sort(ans.begin(), ans.end());
    for (string s: ans) {
        cout << s << endl;
    }
    return 0;
}

This code uses recursion to generate all combinations of parentheses. It uses two parameters: `n` (number of remaining parentheses) and `m` (number of unbalanced parentheses).

The `generateParentheses` function is a recursive function that generates all combinations of parentheses. If `n` is greater than `m` (meaning we have not closed a parenthesis yet), we open a parenthesis and recursively call `generateParentheses` with the remaining number of parentheses (`n - 1`) and the number of unbalanced parentheses (`m + 1`).

If `m` is greater than `n` (meaning we have already balanced a parenthesis), we close a parenthesis and recursively call `generateParentheses` with the remaining number of parentheses (`n`) and the number of balanced parentheses (`m - 1`).

In the main function, we initialize the parameters and call `generateParentheses` with the remaining number of parentheses (`N`) and the number of unbalanced parentheses (`0`). After calling `generateParentheses`, we sort the combinations and print them.