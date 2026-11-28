#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end());

    int min_diff = scores[N-1] - scores[K];
    for (int i = 0; i < N - K; i++) {
        if (scores[i+K] - scores[i] < min_diff) {
            min_diff = scores[i+K] - scores[i];
        }
    }

    cout << min_diff;

    return 0;
}