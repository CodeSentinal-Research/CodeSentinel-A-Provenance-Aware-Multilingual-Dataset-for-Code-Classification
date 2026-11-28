#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSortRecursive(vector<int>& nums, int index, int n) {
    if (index == n) return;
    int minIdx = index;
    for (int j = index + 1; j < n; ++j) {
        if (nums[j] < nums[minIdx]) minIdx = j;
    }
    swap(nums[index], nums[minIdx]);
    selectionSortRecursive(nums, index + 1, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    selectionSortRecursive(nums, 0, n);
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
