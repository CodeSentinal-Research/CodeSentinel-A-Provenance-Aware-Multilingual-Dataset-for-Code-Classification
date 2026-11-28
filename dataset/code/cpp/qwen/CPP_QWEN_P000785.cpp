#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    
    for (int i = 0; i < n; ++i) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            cout << i << endl;
            return 0;
        }
        leftSum += nums[i];
    }
    cout << -1 << endl;
    return 0;
}
