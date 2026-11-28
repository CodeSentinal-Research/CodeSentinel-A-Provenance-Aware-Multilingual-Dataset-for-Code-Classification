#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findSubsequences(vector<int>& nums, int target, vector<int>& current, vector<vector<int>>& results) {
    if (target == 0) {
        results.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > target) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        current.push_back(nums[i]);
        findSubsequences(nums, target - nums[i], current, results);
        current.pop_back();
    }
}

void printSubsequences(vector<int>& nums, int target) {
    vector<vector<int>> results;
    vector<int> current;
    findSubsequences(nums, target, current, results);

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> target;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    printSubsequences(nums, target);

    return 0;
}