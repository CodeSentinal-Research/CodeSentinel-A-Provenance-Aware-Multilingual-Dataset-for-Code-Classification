#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.rbegin(), nums.rend());
    
    long long prefixSum = 0;
    int positivePrefixes = 0;
    
    for (int num : nums) {
        prefixSum += num;
        if (prefixSum > 0) {
            positivePrefixes++;
        } else {
            break;
        }
    }
    
    cout << positivePrefixes << endl;
    return 0;
}
