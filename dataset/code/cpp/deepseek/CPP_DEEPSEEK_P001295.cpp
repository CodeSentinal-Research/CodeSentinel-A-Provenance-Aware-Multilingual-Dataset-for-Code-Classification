#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> marbles(N);
    for (int i = 0; i < N; ++i) {
        cin >> marbles[i];
    }

    sort(marbles.begin(), marbles.end());

    int max_score = 0;
    for (int i = 0; i < K - 1; ++i) {
        max_score += marbles[i];
    }

    int min_score = marbles[0];
    for (int i = 0; i < K - 1; ++i) {
        min_score += marbles[i];
    }

    int diff = max_score - min_score;

    cout << diff << endl;

    return 0;
}