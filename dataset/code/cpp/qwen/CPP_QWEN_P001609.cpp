#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
    long long leftSum = 0;
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        // rightSum = totalSum - leftSum - nums[i]
        if (leftSum == totalSum - leftSum - nums[i]) {
            count++;
        }
        leftSum += nums[i];
    }
    
    cout << count << endl;
    return 0;
}
