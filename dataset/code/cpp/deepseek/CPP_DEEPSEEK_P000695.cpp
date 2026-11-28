#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(int index, int target, const vector<int>& nums) {
    if(index < 0) {
        return -1;
    }
    if(nums[index] == target) {
        return index;
    }
    return firstOccurrence(index-1, target, nums);
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = firstOccurrence(n-1, target, nums);
    cout << result << endl;
    return 0;
}