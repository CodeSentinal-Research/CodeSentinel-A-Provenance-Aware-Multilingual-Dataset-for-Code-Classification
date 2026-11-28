int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int tails[numsSize];
    int size = 0;
    for (int k = 0; k < numsSize; k++) {
        int x = nums[k];
        int l = 0, r = size;
        while (l < r) {
            int m = (l + r) / 2;
            if (tails[m] < x) l = m + 1;
            else r = m;
        }
        tails[l] = x;
        if (l == size) size++;
    }
    return size;
}