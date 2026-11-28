#include <iostream>
#include <vector>
using namespace std;

void insertionSortRecursive(vector<int>& nums, int n) {
    if (n <= 1) return;
    insertionSortRecursive(nums, n - 1);
    int last = nums[n - 1];
    int j = n - 2;
    while (j >= 0 && nums[j] > last) {
        nums[j + 1] = nums[j];
        j--;
    }
    nums[j + 1] = last;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    insertionSortRecursive(nums, n);
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
