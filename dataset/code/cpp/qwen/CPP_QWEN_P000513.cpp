#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string>& tokens) {
    for (string& t : tokens) {
        if (t != "[" && t != "]" && t != ",") cout << t << " ";
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    vector<string> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    solve(t);
    return 0;
}
