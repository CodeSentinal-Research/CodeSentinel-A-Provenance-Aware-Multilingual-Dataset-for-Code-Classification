int countKDifference(int* nums, int numsSize, int k) {
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int diff = nums[i] - nums[j];
            if (diff == k || diff == -k) ans++;
        }
    }
    return ans;
}