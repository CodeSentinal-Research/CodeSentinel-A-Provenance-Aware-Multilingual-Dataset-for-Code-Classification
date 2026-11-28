#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{
    int left = 0;
    int right = 0;
    int maxlen = 0;
    int n = nums.size();
    int sum = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (sum <= k)
        {
            right++;
            sum += nums[right];
        }
        else
        {
            sum -= nums[left];
            left++;
        }
    }
    if (sum == k)
        return max(right - left + 1, maxlen);
    else
        return 0;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    cout << "The length of the longest subarray with sum equal to k is: " << longestSubarray(nums, k) << endl;
    return 0;
}