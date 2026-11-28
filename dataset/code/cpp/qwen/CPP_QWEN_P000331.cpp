#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> logs(m);
    for (int i = 0; i < m; i++) cin >> logs[i];
    vector<int> res(n, 0);
    stack<pair<int, int>> st;
    for (const string& log : logs) {
        int id = stoi(log.substr(0, log.find(':')));
        string type = log.substr(log.find(':') + 1, log.rfind(':') - log.find(':') - 1);
        int time = stoi(log.substr(log.rfind(':') + 1));
        if (type == "start") {
            if (!st.empty()) res[st.top().first] += time - st.top().second;
            st.push({id, time});
        } else {
            res[id] += time - st.top().second + 1;
            st.pop();
            if (!st.empty()) st.top().second = time + 1;
        }
    }
    for (int i = 0; i < n; i++) cout << res[i] << (i == n - 1 ? "" : " ");
    cout << endl;
    return 0;
}
