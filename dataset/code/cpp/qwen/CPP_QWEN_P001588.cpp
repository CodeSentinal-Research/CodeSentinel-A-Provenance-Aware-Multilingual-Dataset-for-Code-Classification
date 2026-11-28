#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Transform: odd -> 1, even -> 0. Find subarrays with sum K.
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int currentSum = 0;
    long long count = 0;
    
    for (int num : nums) {
        currentSum += (num % 2 != 0 ? 1 : 0);
        if (prefixCount.find(currentSum - k) != prefixCount.end()) {
            count += prefixCount[currentSum - k];
        }
        prefixCount[currentSum]++;
    }
    
    cout << count << endl;
    return 0;
}
