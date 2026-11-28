#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(vector<int>& nums, int i, int n) {
    if (i >= n) return true;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && nums[i] < nums[left]) return false;
    if (right < n && nums[i] < nums[right]) return false;
    
    return isMaxHeap(nums, left, n) && isMaxHeap(nums, right, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << (isMaxHeap(nums, 0, n) ? "true" : "false") << endl;
    return 0;
}
