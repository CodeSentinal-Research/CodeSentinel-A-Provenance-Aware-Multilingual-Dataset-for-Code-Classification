#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    NumArray obj(nums);
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << obj.sumRange(l, r) << endl;
    }
    return 0;
}
