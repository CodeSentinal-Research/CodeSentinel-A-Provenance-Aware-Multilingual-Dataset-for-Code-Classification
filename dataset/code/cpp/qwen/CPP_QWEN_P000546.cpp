#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool solve(string s, int minJump, int maxJump) {
    int n = s.length();
    if (s[n-1] == '1') return false;
    queue<int> q; q.push(0);
    int max_reached = 0;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        int start = max(i + minJump, max_reached + 1);
        int end = min(i + maxJump, n - 1);
        for (int j = start; j <= end; j++) {
            if (s[j] == '0') {
                if (j == n - 1) return true;
                q.push(j);
            }
        }
        max_reached = max(max_reached, end);
    }
    return false;
}

int main() {
    string s; int minJ, maxJ; cin >> s >> minJ >> maxJ;
    cout << (solve(s, minJ, maxJ) ? "true" : "false") << endl;
    return 0;
}
