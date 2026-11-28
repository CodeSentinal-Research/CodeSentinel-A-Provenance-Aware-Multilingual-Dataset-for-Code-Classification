#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    auto it = find(nums.begin(), nums.end(), target);
    if (it != nums.end()) {
        return it - nums.begin();
    } else {
        return -1;
    }
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    cout << search(nums, target) << endl;

    return 0;
}