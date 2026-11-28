int mostFrequent(int* nums, int numsSize, int key) {
    int count[1005] = {0};
    int maxCount = 0, bestTarget = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == key) {
            int target = nums[i + 1];
            count[target]++;
            if (count[target] > maxCount) {
                maxCount = count[target];
                bestTarget = target;
            }
        }
    }
    return bestTarget;
}