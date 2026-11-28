int longestOnes(int* nums, int numsSize, int k) {
    int l = 0;
    for (int r = 0; r < numsSize; r++) {
        if (nums[r] == 0) k--;
        if (k < 0) {
            if (nums[l] == 0) k++;
            l++;
        }
    }
    return numsSize - l;
}