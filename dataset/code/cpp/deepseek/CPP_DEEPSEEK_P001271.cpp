#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> watering_ranges(N + 1);
    for (int i = 0; i < N + 1; ++i) {
        cin >> watering_ranges[i];
    }

    vector<int> dp(N + 2, -1);
    dp[N + 1] = 0;

    for (int i = N; i >= 0; --i) {
        int tap_count = 0;
        for (int j = i; j < N + 1; ++j) {
            if (j >= watering_ranges[j]) {
                tap_count++;
            } else {
                break;
            }
        }

        dp[i] = tap_count == 0 ? -1 : max(tap_count, dp[i + 1]);
    }

    if (dp[0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dp[0] << endl;
    }

    return 0;
}

This program uses a dynamic programming approach to solve the problem. It starts from the end of the garden (N) and calculates the maximum number of taps required to water the garden. If it's impossible to water the garden completely (i.e., there's no tap that can fully water the garden), it sets the number of taps to -1. If it's possible, it sets the number of taps to the maximum of the number of taps required to water the garden and the remaining garden. The process is repeated for each tap from the start to the end of the garden.