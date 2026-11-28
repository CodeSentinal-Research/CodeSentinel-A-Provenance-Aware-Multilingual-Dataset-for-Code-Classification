int mostFrequent(int* nums, int numsSize) {
    int maxCnt = 0, best = nums[0];
    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == nums[i]) cnt++;
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            best = nums[i];
        }
    }
    return best;
}