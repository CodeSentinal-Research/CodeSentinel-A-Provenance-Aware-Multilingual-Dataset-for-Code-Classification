#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> distances(N);
    vector<int> speeds(N);

    for (int i = 0; i < N; i++) {
        cin >> distances[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> speeds[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        pq.push(distances[i]);
    }

    int eliminations = 0;

    while (!pq.empty()) {
        int monster = pq.top();
        pq.pop();

        monster -= speeds[eliminations];

        if (monster < 0) {
            break;
        }

        eliminations++;
    }

    cout << eliminations << endl;

    return 0;
}