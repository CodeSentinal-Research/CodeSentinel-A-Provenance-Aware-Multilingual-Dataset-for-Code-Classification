#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int start = 0, end = 0, sum = 0, maxLen = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (end < N) {
        sum += A[end];
        pq.push(A[end]);

        while (start < end && sum >= K) {
            sum -= pq.top();
            pq.pop();
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
        end++;
    }

    cout << maxLen << endl;

    return 0;
}