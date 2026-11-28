#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, goal;
    cin >> n >> goal;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Prefix sum approach for binary array
    // Count subarrays with sum K
    // Use map to store frequency of prefix sums
    
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int currentSum = 0;
    long long count = 0;
    
    for (int num : nums) {
        currentSum += num;
        if (prefixCount.find(currentSum - goal) != prefixCount.end()) {
            count += prefixCount[currentSum - goal];
        }
        prefixCount[currentSum]++;
    }
    
    cout << count << endl;
    return 0;
}
