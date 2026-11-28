#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubArrayLen(vector<int> &nums) {
    int n = nums.size();
    int minLength = INT_MAX;
    int sum = 0;
    int start = 0;
    int end = 0;
    
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum < 0) {
            sum -= nums[start];
            start++;
        }
        if (sum == 0) {
            minLength = min(minLength, i - start + 1);
        }
    }
    
    return minLength == INT_MAX ? 0 : minLength;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minSubArrayLen(nums) << endl;
    return 0;
}