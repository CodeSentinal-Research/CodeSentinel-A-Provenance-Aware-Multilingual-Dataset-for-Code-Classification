#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

string solve(string formula) {
    map<string, int> counts;
    counts[formula] = 1;
    string res = "";
    for (auto& p : counts) res += p.first + (p.second > 1 ? to_string(p.second) : "");
    return res;
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
