#include <iostream>
#include <string>
#include <queue>
using namespace std;

string solve(string senate) {
    queue<int> r, d;
    for (int i = 0; i < senate.length(); i++) {
        if (senate[i] == 'R') r.push(i);
        else d.push(i);
    }
    while (!r.empty() && !d.empty()) {
        int r_idx = r.front(), d_idx = d.front();
        r.pop(); d.pop();
        if (r_idx < d_idx) r.push(r_idx + senate.length());
        else d.push(d_idx + senate.length());
    }
    return r.empty() ? "Dire" : "Radiant";
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
