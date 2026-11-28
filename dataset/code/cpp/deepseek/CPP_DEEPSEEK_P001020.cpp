#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int K;
    cin >> K;

    vector<vector<int>> lists(K);
    for (int i = 0; i < K; i++) {
        int M;
        cin >> M;
        lists[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> lists[i][j];
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < K; i++) {
        pq.push({ lists[i][0], i });
    }

    int start = pq.top().first;
    int end = start;
    int minStart = start;
    int minEnd = start;

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        if (p.first > end) {
            start = p.first;
        }
        end = max(end, p.first);
        if (end - start < minEnd - minStart) {
            minStart = start;
            minEnd = end;
        }
        if (pq.empty() || pq.top().first != lists[p.second][0]) {
            pq.push({ lists[p.second][0], p.second });
        }
    }

    cout << minStart << ' ' << minEnd;

    return 0;
}