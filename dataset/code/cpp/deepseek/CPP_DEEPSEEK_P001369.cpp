#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

void solve(string s, int start, int end, int lp, int rp, unordered_set<string> &res) {
    if (start > end) return;
    if (lp == 0 && rp == 0) {
        if (res.find(s) == res.end()) {
            res.insert(s);
            cout << s << endl;
        }
        return;
    }
    if (s[start] == '(' && lp > 0) {
        solve(s, start + 1, end, lp - 1, rp, res);
    }
    if (s[start] == ')' && rp > 0) {
        solve(s, start + 1, end, lp, rp - 1, res);
    }
    solve(s, start + 1, end, lp, rp, res);
}

int main() {
    string s;
    cin >> s;
    unordered_set<string> res;
    solve(s, 0, s.length() - 1, 1, 0, res);
    return 0;
}
This C++ code will solve the problem as per the constraints. It uses a depth-first search (DFS) approach to generate all the valid parentheses strings by adding parentheses at each possible location. The function `solve` takes a string, two indices, two counts of parentheses to be removed, and a set to store the results. It recursively adds parentheses at each possible location until all parentheses are removed. If a valid string is found, it's inserted into the set and printed.