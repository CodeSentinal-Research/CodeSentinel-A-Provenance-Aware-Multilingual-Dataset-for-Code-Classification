#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dpArr[40005];

int longestSubsequence(int* arr, int arrSize, int difference) {
    for (int i = 0; i < 40005; i++) dpArr[i] = 0;
    int offset = 20000;
    int maxLen = 0;

    for (int i = 0; i < arrSize; i++) {
        int prev = arr[i] - difference + offset;
        int len = 1;
        if (prev >= 0 && prev < 40005 && dpArr[prev] > 0) {
            len = dpArr[prev] + 1;
        }
        dpArr[arr[i] + offset] = len;
        maxLen = MAX(maxLen, len);
    }
    return maxLen;
}