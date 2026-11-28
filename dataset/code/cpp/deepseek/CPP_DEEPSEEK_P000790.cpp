#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool checkSubarraySum(int k, vector<int>& nums) {
    unordered_set<int> seen{0};
    int sum = 0;
    for (int num : nums) {
        sum += num;
        if (k != 0) sum %= k;
        if (seen.count(sum)) return true;
        seen.insert(sum);
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    if (checkSubarraySum(k, nums)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}