#include <iostream>
#include <vector>
using namespace std;

int countOccurrencesRecursive(const vector<int>& nums, int index, int target) {
    if (index == nums.size()) return 0;
    int count = (nums[index] == target) ? 1 : 0;
    return count + countOccurrencesRecursive(nums, index + 1, target);
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> target;
    
    cout << countOccurrencesRecursive(nums, 0, target) << endl;
    return 0;
}
