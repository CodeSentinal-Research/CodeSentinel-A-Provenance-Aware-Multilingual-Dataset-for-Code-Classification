int findMaxConsecutiveOnes(int* nums, int n) {
    int best = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur = (nums[i] == 1) ? cur + 1 : 0;
        if (cur > best) best = cur;
    }
    return best;
}
