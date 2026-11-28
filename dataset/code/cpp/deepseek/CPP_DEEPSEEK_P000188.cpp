#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<pair<int, int>, int> subarraySum(vector<int>& nums, int sum) {
    int start = 0, end = 0;
    int curSum = nums[0];

    unordered_map<int, int> map;
    map[0] = 1;

    while (start < nums.size()) {
        while (curSum < sum && end < nums.size()) {
            end++;
            curSum += nums[end];
        }

        if (curSum == sum) {
            return make_pair(make_pair(start + 1, end), sum);
        }

        curSum -= nums[start];
        start++;
    }

    return make_pair(make_pair(-1, -1), -1);
}

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    auto result = subarraySum(nums, sum);

    if (result.first.first != -1) {
        cout << "Starting index: " << result.first.first << ", Ending index: " << result.first.second << "\n";
    } else {
        cout << "No subarray found\n";
    }

    return 0;
}