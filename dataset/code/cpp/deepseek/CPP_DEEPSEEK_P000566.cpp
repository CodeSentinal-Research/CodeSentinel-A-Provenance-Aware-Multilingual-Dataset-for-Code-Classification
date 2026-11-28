#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int minMutation(string start, string end, int n, vector<string> bank) {
    unordered_set<string> s(bank.begin(), bank.end());
    queue<pair<string, int>> q;
    q.push({start, 0});
    s.erase(start);
    while (!q.empty()) {
        string t = q.front().first;
        int step = q.front().second;
        q.pop();
        if (t == end)
            return step;
        for (int i = 0; i < 8; i++)
            for (int j = i + 1; j < 8; j++) {
                swap(t[i], t[j]);
                if (s.count(t)) {
                    q.push({t, step + 1});
                    s.erase(t);
                }
                swap(t[i], t[j]);
            }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<string> bank(n);
    for (int i = 0; i < n; i++) {
        cin >> bank[i];
    }
    string start, end;
    cin >> start >> end;
    int res = minMutation(start, end, n, bank);
    if (res == -1)
        cout << "Mutation impossible";
    else
        cout << "Minimum Mutations: " << res;
    return 0;
}