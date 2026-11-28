#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0, count = 0;
    m[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (m.find(sum - k) != m.end()) {
            count += m[sum - k];
        }
        m[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1, 1};
    int k = 2;
    cout << subarraySum(nums, k);
    return 0;
}