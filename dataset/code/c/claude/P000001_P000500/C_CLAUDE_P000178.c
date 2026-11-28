#include <stdlib.h>
#include <string.h>
static int* freq_arr;
static int freq_n;
int cmpFreq(const void* a, const void* b) {
    int fa = freq_arr[*(int*)a], fb = freq_arr[*(int*)b];
    if (fa != fb) return fb - fa;
    return *(int*)a - *(int*)b;
}
int* frequencySort(int* nums, int n, int* returnSize) {
    // Simple O(n^2) for generality
    *returnSize = n;  // write through pointer
    int* cnt = (int*)calloc(2001, sizeof(int));
    for (int i = 0; i < n; i++) cnt[nums[i] + 1000]++;
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[i] = nums[i];
    // Bubble sort by frequency
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            int fa = cnt[res[j]+1000], fb = cnt[res[j+1]+1000];
            if (fa < fb || (fa == fb && res[j] > res[j+1])) {
                int t = res[j]; res[j] = res[j+1]; res[j+1] = t;
            }
        }
    free(cnt);
    return res;
}
