#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    long long maxSubArray(vector<long long>& nums) {
        long long maxSum = LLONG_MIN, curr = 0;
        for (long long x : nums) {
            curr += x;
            maxSum = max(maxSum, curr);
            if (curr < 0) curr = 0;
        }
        return maxSum;
    }
};
int main() {
    int n; cin >> n;
    vector<long long> nums(n);
    for (auto& x : nums) cin >> x;
    cout << Solution().maxSubArray(nums) << "\n";
}
