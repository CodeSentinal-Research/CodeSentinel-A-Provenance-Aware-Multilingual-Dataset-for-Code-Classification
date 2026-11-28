#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int maxProduct = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int maxProductWithMinusOne = nums[0] * nums[1] * nums[n - 1];

    int maxProductWithAll = max(maxProduct, maxProductWithMinusOne);

    cout << maxProductWithAll;

    return 0;
}