#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BrowserHistory {
    vector<string> history; int curr;
public:
    BrowserHistory(string homepage) { history.push_back(homepage); curr = 0; }
    void visit(string url) { history.resize(curr + 1); history.push_back(url); curr++; }
    string back(int steps) { curr = max(0, curr - steps); return history[curr]; }
    string forward(int steps) { curr = min((int)history.size() - 1, curr + steps); return history[curr]; }
};

int main() {
    string home; cin >> home;
    BrowserHistory bh(home);
    int q; cin >> q;
    while(q--) {
        string op, url; int steps; cin >> op;
        if(op == "visit") { cin >> url; bh.visit(url); }
        else if(op == "back") { cin >> steps; cout << bh.back(steps) << " "; }
        else if(op == "forward") { cin >> steps; cout << bh.forward(steps) << " "; }
    }
    cout << endl;
    return 0;
}
