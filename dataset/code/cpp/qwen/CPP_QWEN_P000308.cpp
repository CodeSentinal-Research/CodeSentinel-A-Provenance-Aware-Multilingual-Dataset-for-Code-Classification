#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solve(const string& s, int l, int r) {
    vector<int> res;
    if (l == r) {
        res.push_back(stoi(s.substr(l, 1)));
        return res;
    }
    for (int i = l + 1; i < r; i += 2) {
        vector<int> left = solve(s, l, i - 1);
        vector<int> right = solve(s, i + 1, r);
        for (int l_val : left) {
            for (int r_val : right) {
                if (s[i] == '+') res.push_back(l_val + r_val);
                else if (s[i] == '-') res.push_back(l_val - r_val);
                else if (s[i] == '*') res.push_back(l_val * r_val);
            }
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<int> res = solve(s, 0, s.size() - 1);
    for (int v : res) cout << v << endl;
    return 0;
}
