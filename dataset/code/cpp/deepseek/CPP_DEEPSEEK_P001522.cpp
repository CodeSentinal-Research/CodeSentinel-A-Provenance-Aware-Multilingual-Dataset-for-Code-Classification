Here is the code:

#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int total = 0;
    for (int num : nums)
        total += num;
    if (total < x)
        return -1;
    int operations = 0;
    int current_sum = 0;
    for (int left = 0, right = nums.size() - 1; left < right; ++left) {
        while (current_sum < x && left < right)
            current_sum += nums[right--];
        if (current_sum == x) {
            if (left > 0)
                operations += left;
            else
                operations += right;
            current_sum = 0;
            --right;
        }
    }
    return (total - current_sum == x) ? operations : -1;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> nums(N);
    for (int& num : nums)
        cin >> num;
    cout << minOperations(nums, X);
    return 0;
}

This code uses two pointers, one from the beginning and one from the end, to try and minimize the sum of the remaining elements in the array. If the sum exceeds X, it decreases the sum and increases the operations. If the sum equals X, it adds the number of elements left to the operations and resets the sum.