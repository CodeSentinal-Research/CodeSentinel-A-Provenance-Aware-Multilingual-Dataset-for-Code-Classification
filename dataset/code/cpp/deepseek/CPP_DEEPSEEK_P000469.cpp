Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> searchRange(vector<int>& nums, int target) {
    auto lower = lower_bound(nums.begin(), nums.end(), target);
    auto upper = upper_bound(nums.begin(), nums.end(), target);
    
    if (lower == nums.end() || upper == nums.end() || *lower != target) {
        return {-1, -1};
    }

    return {lower - nums.begin(), upper - nums.begin() - 1};
}

int main() {
    int N, target;
    cin >> N >> target;
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    pair<int, int> result = searchRange(nums, target);
    cout << result.first << ' ' << result.second << '\n';
    
    return 0;
}

This code defines a function `searchRange` that takes a sorted vector of integers and a target integer, and returns a pair of indices indicating the range of the target in the vector. The indices are returned as `(lower_bound - nums.begin(), upper_bound - nums.begin() - 1)`. The `lower_bound` and `upper_bound` functions are part of the C++ Standard Library.

In the `main` function, we read the size of the array (N) and the target value from the standard input, then read the array itself. We then call `searchRange` with these values to get the result and print it out.