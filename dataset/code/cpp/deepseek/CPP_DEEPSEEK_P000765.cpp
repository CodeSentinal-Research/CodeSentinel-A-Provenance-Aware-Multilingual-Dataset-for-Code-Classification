#include <iostream>
#include <vector>

using namespace std;

bool isMaxHeap(vector<int>& nums, int index, int n) {
    if (index > n) {
        return true;
    }
    
    if (2*index+1 < n && nums[index] < nums[2*index+1]) {
        return false;
    }
    
    if (2*index+2 < n && nums[index] < nums[2*index+2]) {
        return false;
    }
    
    return isMaxHeap(nums, 2*index+1, n) && isMaxHeap(nums, 2*index+2, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << (isMaxHeap(nums, 0, n) ? "true" : "false");
    
    return 0;
}