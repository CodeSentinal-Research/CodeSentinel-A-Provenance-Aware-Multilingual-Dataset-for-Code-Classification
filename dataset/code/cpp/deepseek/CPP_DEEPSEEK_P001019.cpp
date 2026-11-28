#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

pair<int, int> input() {
    int x, y;
    cin >> x >> y;
    return make_pair(x, y);
}

double euclideanDistance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<pair<int, int>> kClosestPoints(int N, int K, pair<int, int> origin) {
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

    for (int i = 0; i < N; i++) {
        pair<int, int> current = input();
        double distance = euclideanDistance(origin, current);
        pq.push(make_pair(distance, current));

        if (pq.size() > K) {
            pq.pop();
        }
    }

    vector<pair<int, int>> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    pair<int, int> origin = input();
    vector<pair<int, int>> result = kClosestPoints(N, K, origin);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << ' ' << result[i].second << '\n';
    }

    return 0;
}