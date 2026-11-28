#include <stdlib.h>
int cmpT(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* findTriplet(int* nums, int n, int target, int* returnSize) {
    qsort(nums, n, sizeof(int), cmpT);
    for (int i = 0; i < n-2; i++) {
        int l = i+1, r = n-1;
        while (l < r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s == target) {
                *returnSize = 3;  // write through pointer
                int* res = (int*)malloc(3*sizeof(int));
                res[0]=nums[i]; res[1]=nums[l]; res[2]=nums[r];
                return res;
            } else if (s < target) l++;
            else r--;
        }
    }
    *returnSize = 0;  // write through pointer
    return NULL;
}
