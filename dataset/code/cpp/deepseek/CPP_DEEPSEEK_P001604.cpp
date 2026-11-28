#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> prefixSums;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += nums[i];
        if (sum == K) {
            count++;
            sum = 0;
        } else if (prefixSums.find(sum - K) != prefixSums.end()) {
            count += prefixSums[sum - K];
        }
        if (prefixSums.find(sum) == prefixSums.end()) {
            prefixSums[sum] = 1;
        } else {
            prefixSums[sum]++;
        }
    }
    cout << count << endl;
    return 0;
}