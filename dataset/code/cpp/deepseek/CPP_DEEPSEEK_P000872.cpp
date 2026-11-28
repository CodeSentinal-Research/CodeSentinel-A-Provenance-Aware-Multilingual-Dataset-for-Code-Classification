#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int maxXORpair(vector<int> &nums) {
    int n = nums.size();
    int res = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++) {
        int xor = nums[i] ^ nums[i + 1];

        res = max(res, xor);
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxXORpair(nums);

    return 0;
}