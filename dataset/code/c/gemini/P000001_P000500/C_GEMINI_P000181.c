#define MAX(a, b) ((a) > (b) ? (a) : (b))

int helperOverlap(int* nums, int n, int L, int M) {
    int sumL = 0, sumM = 0;
    for (int i = 0; i < L; i++) sumL += nums[i];
    for (int i = L; i < L + M; i++) sumM += nums[i];

    int maxL = sumL;
    int ans = sumL + sumM;

    for (int i = L + M; i < n; i++) {
        sumL += nums[i - M] - nums[i - L - M];
        maxL = MAX(maxL, sumL);
        sumM += nums[i] - nums[i - M];
        ans = MAX(ans, maxL + sumM);
    }
    return ans;
}

int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen) {
    return MAX(helperOverlap(nums, numsSize, firstLen, secondLen), helperOverlap(nums, numsSize, secondLen, firstLen));
}