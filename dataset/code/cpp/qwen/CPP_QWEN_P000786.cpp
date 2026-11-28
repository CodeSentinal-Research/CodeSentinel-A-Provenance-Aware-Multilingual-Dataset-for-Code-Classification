#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    vector<int> result(n);
    
    for (int i = 0; i < n; ++i) {
        int rightSum = totalSum - leftSum - nums[i];
        result[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}
