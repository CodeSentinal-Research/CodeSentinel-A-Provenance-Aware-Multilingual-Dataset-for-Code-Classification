#include <iostream>
#include <vector>
using namespace std;

void bubbleSortRecursive(vector<int>& nums, int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
    }
    bubbleSortRecursive(nums, n - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    bubbleSortRecursive(nums, n);
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
