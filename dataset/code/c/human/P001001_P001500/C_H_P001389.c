//longest subarray
#include <stdio.h>

#define MAX_LENGTH 100

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int longestSubarray(int arr[], int n) {
    int maxLength = 0;
    int sum = 0;
    int index[MAX_LENGTH * 2 + 1];
    int i;

    for (i = 0; i < MAX_LENGTH * 2 + 1; i++) {
        index[i] = -1;
    }

    for (i = 0; i < n; i++) {
        sum += (arr[i] == 0) ? -1 : 1;

        if (sum == 0) {
            maxLength = i + 1;
        } else if (index[sum + MAX_LENGTH] != -1) {
            maxLength = max(maxLength, i - index[sum + MAX_LENGTH]);
        } else {
            index[sum + MAX_LENGTH] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of the longest subarray with equal number of 0s and 1s: %d\n", longestSubarray(arr, n));
    return 0;
}