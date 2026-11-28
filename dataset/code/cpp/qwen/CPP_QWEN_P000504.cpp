#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<int> solve(int n, vector<string>& logs) {
    vector<int> res(n, 0);
    stack<pair<int, int>> st;
    for (string& log : logs) {
        size_t p1 = log.find(':'), p2 = log.find(':', p1 + 1);
        int id = stoi(log.substr(0, p1));
        int time = stoi(log.substr(p2 + 1));
        if (log[p1 + 1] == 's') {
            if (!st.empty()) res[st.top().first] += time - st.top().second;
            st.push({id, time});
        } else {
            auto top = st.top(); st.pop();
            res[id] += time - top.second + 1;
            if (!st.empty()) st.top().second = time + 1;
        }
    }
    return res;
}

int main() {
    int n, m; cin >> n >> m;
    vector<string> logs(m);
    for(int i = 0; i < m; i++) cin >> logs[i];
    vector<int> ans = solve(n, logs);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
