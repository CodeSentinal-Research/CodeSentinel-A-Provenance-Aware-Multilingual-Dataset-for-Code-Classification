#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int N, vector<string> &words, string available_letters, vector<int> &scores) {
    vector<bool> used(N);
    vector<int> dp(1 << N, -1e9);
    dp[0] = 0;

    for (int mask = 0; mask < 1 << N; ++mask) {
        if (dp[mask] == -1e9) continue;
        for (int i = 0; i < N; ++i) {
            if (!(mask & (1 << i))) {
                int next_mask = mask | (1 << i);
                string word = words[i];
                int score = 0;
                for (char c : word) {
                    int idx = c - 'a';
                    score += scores[idx];
                }
                if (score > 0) {
                    int max_score = -1e9;
                    for (char c : word) {
                        int idx = c - 'a';
                        max_score = max(max_score, dp[mask | (1 << i)] + score);
                    }
                    dp[next_mask] = max(dp[next_mask], max_score);
                }
            }
        }
    }

    int res = -1e9;
    for (int mask = 0; mask < 1 << N; ++mask) {
        if (dp[mask] != -1e9) {
            string word = "";
            for (int i = 0; i < N; ++i) {
                if ((mask & (1 << i)) && (available_letters[i] == '1')) {
                    word += words[i];
                    break;
                }
            }
            for (char c : word) {
                int idx = c - 'a';
                res = max(res, dp[mask] + scores[idx]);
            }
        }
    }

    return res;
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }
    string available_letters(N, '0');
    cin >> available_letters;
    vector<int> scores(26);
    for (int i = 0; i < 26; ++i) {
        cin >> scores[i];
    }
    int result = solve(N, words, available_letters, scores);
    cout << result << '\n';
    return 0;
}