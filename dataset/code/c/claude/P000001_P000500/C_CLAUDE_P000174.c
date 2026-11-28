#include <stdlib.h>
#include <limits.h>
int cmpMD(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int minDifference(int* nums, int n) {
    qsort(nums, n, sizeof(int), cmpMD);
    int minDiff = INT_MAX;
    for (int i=1;i<n;i++) {
        int d=nums[i]-nums[i-1];
        if(d<minDiff) minDiff=d;
    }
    return minDiff;
}
