#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(arr[i]);
        if (pq.size() > K) {
            pq.pop();
        }
    }

    int score = 0;
    while (!pq.empty()) {
        score += pq.top();
        pq.pop();
    }

    cout << score << endl;

    return 0;
}