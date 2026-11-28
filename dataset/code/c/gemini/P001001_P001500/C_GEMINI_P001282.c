#include <stdlib.h>
#include <stdbool.h>

bool greaterArr(int* nums1, int p1, int len1, int* nums2, int p2, int len2) {
    while (p1 < len1 && p2 < len2 && nums1[p1] == nums2[p2]) {
        p1++;
        p2++;
    }
    return p2 == len2 || (p1 < len1 && nums1[p1] > nums2[p2]);
}

int* maxSingleC(int* nums, int numsSize, int k) {
    int* stack = (int*)malloc(k * sizeof(int));
    int top = -1, drop = numsSize - k;
    for (int i = 0; i < numsSize; i++) {
        while (top >= 0 && stack[top] < nums[i] && drop > 0) {
            top--;
            drop--;
        }
        if (top < k - 1) {
            stack[++top] = nums[i];
        } else {
            drop--;
        }
    }
    return stack;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    *returnSize = k;
    int* maxArr = (int*)calloc(k, sizeof(int));

    int start = (k - nums2Size > 0) ? k - nums2Size : 0;
    int end = (k < nums1Size) ? k : nums1Size;

    for (int i = start; i <= end; i++) {
        int* s1 = maxSingleC(nums1, nums1Size, i);
        int* s2 = maxSingleC(nums2, nums2Size, k - i);
        int* cand = (int*)malloc(k * sizeof(int));
        int p1 = 0, p2 = 0;

        for (int j = 0; j < k; j++) {
            cand[j] = greaterArr(s1, p1, i, s2, p2, k - i) ? s1[p1++] : s2[p2++];
        }

        if (greaterArr(cand, 0, k, maxArr, 0, k)) {
            for (int j = 0; j < k; j++) maxArr[j] = cand[j];
        }
        free(s1);
        free(s2);
        free(cand);
    }
    return maxArr;
}