Here is the C++ code for your problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums) {
    long long count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int positive = 0, negative = 0;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > 0) {
                positive++;
            } else {
                negative++;
           
            }
            if (positive == negative && positive > 0) {
                count += positive;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {3, 1, -4, 2, -2};
    cout << countSubarrays(nums);
    return 0;
}
This code counts the number of valid subarrays with equal number of positive and negative elements. It first iterates through the array, and for each element, it counts the number of positive and negative numbers. If the number of positive numbers equals the number of negative numbers and they're both greater than 0, it adds the count of positive numbers to the total count. This process is repeated for all subarrays.