#include <iostream>
#include <vector>
using namespace std;

void productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        output[i] *= prefix;
        prefix *= nums[i];
    }

    prefix = 1;
    for (int i = n - 1; i >= 0; --i) {
        output[i] *= prefix;
        prefix *= nums[i];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    productExceptSelf(nums);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}