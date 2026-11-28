#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> prefixSums;
    int curSum = 0, maxLen = 0;
    for (int i = 0; i < N; i++) {
        curSum += arr[i];
        if (curSum == K) {
            maxLen = max(maxLen, i + 1);
        }
        if (prefixSums.find(curSum - K) != prefixSums.end()) {
            maxLen = max(maxLen, i - prefixSums[curSum - K]);
        }
        if (prefixSums.find(curSum) == prefixSums.end()) {
            prefixSums[curSum] = i;
        }
    }

    cout << maxLen << endl;

    return 0;
}