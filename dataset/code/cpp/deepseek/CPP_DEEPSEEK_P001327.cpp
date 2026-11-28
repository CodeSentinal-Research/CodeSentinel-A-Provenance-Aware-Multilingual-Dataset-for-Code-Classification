Here is a C++ code snippet for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
    result.push_back(current);
    for(int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        printSubsets(nums, result, current, i + 1);
        current.pop_back();
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());
    printSubsets(nums, result, current, 0);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

This code first reads the number of elements N and then the elements themselves. It then sorts the input array to handle duplicate elements. The `printSubsets` function is recursive, which means it calls itself to generate all subsets. It uses a current vector to keep track of the subsets, and a start index to avoid duplicates.

The subsets are then printed out in the `main` function. Each subset is printed on a new line.