#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums, int n) {
        long long expected = (long long)n*(n+1)/2;
        long long actual = 0;
        for (int x : nums) actual += x;
        return (int)(expected - actual);
    }
};
int main() {
    int n; cin >> n;
    vector<int> nums(n-1);
    for (auto& x : nums) cin >> x;
    cout << Solution().missingNumber(nums, n) << "\n";
}
