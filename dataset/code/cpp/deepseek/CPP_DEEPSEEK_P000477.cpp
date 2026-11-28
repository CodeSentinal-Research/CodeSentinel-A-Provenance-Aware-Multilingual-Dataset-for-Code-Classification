#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int leftSum = 0, rightSum = 0;
    for(int num : nums)
        rightSum += num;
    int pivot = -1;
    for(int i = 0; i < nums.size(); i++) {
        rightSum -= nums[i];
        if(leftSum == rightSum) {
            pivot = i;
            break;
        }
        leftSum += nums[i];
    }
    return pivot;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    cout << pivotIndex(nums) << endl;
    return 0;
}