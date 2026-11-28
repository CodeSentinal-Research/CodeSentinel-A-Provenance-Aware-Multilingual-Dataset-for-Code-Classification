#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maximumSumSubarray(int k, int* arr, int n) {
    long long curSum = 0;
    for (int i = 0; i < k; i++) curSum += arr[i];
    long long maxSum = curSum;

    for (int i = k; i < n; i++) {
        curSum += arr[i] - arr[i - k];
        maxSum = MAX(maxSum, curSum);
    }
    return maxSum;
}