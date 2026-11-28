#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        if (umap.find(target - nums[i]) != umap.end()) {
            cout << umap[target - nums[i]] << " " << i << endl;
            return;
        }
        umap[nums[i]] = i;
    }
    cout << "-1" << endl;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    twoSum(nums, target);
    return 0;
}