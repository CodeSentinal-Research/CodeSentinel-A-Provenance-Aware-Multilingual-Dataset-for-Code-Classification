long long countAlternatingSubarrays(int* nums, int numsSize) {
    long long ans = 1, curLen = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            curLen++;
        } else {
            curLen = 1;
        }
        ans += curLen;
    }
    return ans;
}