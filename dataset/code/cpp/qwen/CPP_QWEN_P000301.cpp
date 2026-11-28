#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(const string& s, int idx, int dots, string current, vector<string>& res) {
    if (dots == 3) {
        string last = s.substr(idx);
        if (!last.empty() && stoi(last) <= 255 && (last[0] != '0' || last.size() == 1)) {
            res.push_back(current + last);
        }
        return;
    }
    for (int i = 1; i <= 3 && idx + i <= s.size(); i++) {
        string part = s.substr(idx, i);
        if (stoi(part) <= 255 && (part[0] != '0' || part.size() == 1)) {
            solve(s, idx + i, dots + 1, current + part + ".", res);
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> res;
    solve(s, 0, 0, "", res);
    for (const string& ip : res) cout << ip << endl;
    return 0;
}
