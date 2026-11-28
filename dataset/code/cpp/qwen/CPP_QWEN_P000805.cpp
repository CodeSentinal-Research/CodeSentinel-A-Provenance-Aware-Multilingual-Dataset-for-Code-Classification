#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    // Map positive to 1, negative to -1
    // We want subarray with sum 0 in this mapped array
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int currentSum = 0;
    long long count = 0;

    for (int num : nums) {
        currentSum += (num > 0 ? 1 : -1);
        if (prefixCount.find(currentSum) != prefixCount.end()) {
            count += prefixCount[currentSum];
        }
        prefixCount[currentSum]++;
    }

    cout << count << endl;
    return 0;
}
