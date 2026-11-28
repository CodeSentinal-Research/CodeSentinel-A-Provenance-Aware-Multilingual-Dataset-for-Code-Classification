#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    unordered_map<int, int> count;
    long long valid_pairs = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (nums[i] == nums[j]) {
                ++count[nums[i]];
            }
        }
    }

    for (auto &p : count) {
        int num = p.first;
        int freq = p.second;
        valid_pairs += (long long)freq * (freq - 1) / 2;
    }

    for (auto &p : count) {
        int num = p.first;
        int freq = p.second;
        valid_pairs += (long long)freq * (freq + 1) / 2;
    }

    for (int i = 1; i <= K; ++i) {
        if (count.find(i) != count.end()) {
            valid_pairs -= (long long)count[i] * count[i];
        }
    }

    cout << valid_pairs << "\n";

    return 0;
}