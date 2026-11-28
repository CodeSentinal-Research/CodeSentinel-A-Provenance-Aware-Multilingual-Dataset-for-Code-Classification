#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long minimumSumSubarray(int k, int* arr, int n) {
    long long curSum = 0;
    for (int i = 0; i < k; i++) curSum += arr[i];
    long long minSum = curSum;

    for (int i = k; i < n; i++) {
        curSum += arr[i] - arr[i - k];
        minSum = MIN(minSum, curSum);
    }
    return minSum;
}