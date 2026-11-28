#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (mp.count(target - nums[i]))
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
int main() {
    int n, target; cin >> n >> target;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;
    auto res = Solution().twoSum(nums, target);
    cout << res[0] << " " << res[1] << "\n";
}
