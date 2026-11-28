int findEquilibriumIndex(int* nums, int numsSize) {
    long long totalSum = 0;
    for (int i = 0; i < numsSize; i++) totalSum += nums[i];
    long long leftSum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (leftSum == totalSum - leftSum - nums[i]) return i;
        leftSum += nums[i];
    }
    return -1;
}