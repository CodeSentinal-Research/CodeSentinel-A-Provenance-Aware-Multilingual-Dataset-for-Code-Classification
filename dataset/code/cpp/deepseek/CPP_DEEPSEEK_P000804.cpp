Here is the C++ code for the given problem.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubarrays(vector<int>& nums, int K) {
    unordered_map<int, int> cnt;
    int ans = 0, xorK = 0, n = nums.size();
    cnt[0] = 1;
    for(int i = 0; i < n; i++){
        xorK ^= nums[i];
        if(cnt.count(xorK))
            ans += cnt[xorK];
        else if(xorK == K)
            ans++;
        cnt[xorK]++;
    }
    return ans;
}

int main(){
    vector<int> nums = {2,3,1,2,3};
    int K = 2;
    cout << countSubarrays(nums, K);
    return 0;
}
This code uses the concept of prefix sums and XOR operation to solve the problem. The main idea is to use a XOR operation to convert the array into a prefix sum array, then count the subarrays whose XOR equals to K.

The prefix sum array is calculated by traversing the array from the start to end. For each element, it calculates the XOR with K and adds this XOR to the result. If the calculated XOR is already present in the map, it means there are two elements in the subarray whose XOR is equal to K, so it adds the count of these elements to the result.

The code also handles the case where the XOR of the array is equal to K, it adds 1 to the result.