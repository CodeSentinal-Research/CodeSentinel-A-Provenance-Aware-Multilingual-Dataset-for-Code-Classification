#include <stdlib.h>
int cmpWV(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* waveArray(int* nums, int n) {
    qsort(nums, n, sizeof(int), cmpWV);
    for (int i=0;i<n-1;i+=2) { int t=nums[i]; nums[i]=nums[i+1]; nums[i+1]=t; }
    return nums;
}
