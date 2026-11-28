#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    unordered_map<int, int> prefixSums;
    int maxLen = 0;
    int sum = 0;
    
    for (int end = 0; end < N; end++) {
        sum += nums[end];
        
        if (sum == K) {
            maxLen = max(maxLen, end + 1);
        }
        
        if (prefixSums.find(sum - K) != prefixSums.end()) {
            if (maxLen < end - prefixSums[sum - K]) {
                maxLen = end - prefixSums[sum - K];
            }
        }
        
        if (prefixSums.find(sum) == prefixSums.end()) {
            prefixSums[sum] = end;
        }
    }
    
    cout << maxLen;
    
    return 0;
}
This C++ code reads an integer array and a target sum, and prints out the length of the longest subarray whose sum equals to the target sum. The code uses a map to store the prefix sum and the maximum length of subarray. It iterates over the array and updates the prefix sum and the maximum length. If the current sum equals to the target sum, it updates the maximum length. If the current sum minus the target sum is in the map, it updates the maximum length if the current length is greater than the maximum length. If the current sum is not in the map, it adds the current sum and its index to the map.