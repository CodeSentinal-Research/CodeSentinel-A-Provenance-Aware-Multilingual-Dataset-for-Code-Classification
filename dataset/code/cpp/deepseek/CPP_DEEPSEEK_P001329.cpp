#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPermutations(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        vector<int> perm(nums.begin(), nums.end());
        result.push_back(perm);
    }

    for (int i = start; i < nums.size(); i++) {
        if (i != start && nums[i] == nums[start]) continue; 

        swap(nums[i], nums[start]);
        printPermutations(nums, result, start + 1);
        swap(nums[i], nums[start]); 
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result;
    printPermutations(nums, result, 0);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}