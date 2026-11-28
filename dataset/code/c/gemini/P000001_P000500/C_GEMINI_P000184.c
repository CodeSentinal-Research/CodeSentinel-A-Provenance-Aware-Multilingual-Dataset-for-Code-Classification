#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lenOfLongSubarr(int* arr, int n, int k) {
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                maxLen = MAX(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}