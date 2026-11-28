#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return x;
            seen.insert(x);
        }
        return -1;
    }
};
int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;
    cout << Solution().findDuplicate(nums) << "\n";
}
