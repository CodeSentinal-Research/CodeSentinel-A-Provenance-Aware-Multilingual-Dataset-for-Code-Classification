#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    unordered_set<int> seen;
    int maxSum = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        if (seen.find(nums[i]) != seen.end()) {
            seen.clear();
            sum = 0;
        } else {
            seen.insert(nums[i]);
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum;

    return 0;
}