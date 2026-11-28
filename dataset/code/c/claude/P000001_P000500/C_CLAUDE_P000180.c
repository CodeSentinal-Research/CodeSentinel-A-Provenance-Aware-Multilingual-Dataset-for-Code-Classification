#include <stdlib.h>
int* majorityElementNBy3(int* nums, int n, int* returnSize) {
    int c1 = 0, c2 = 1, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i]==c1) cnt1++;
        else if (nums[i]==c2) cnt2++;
        else if (cnt1==0) { c1=nums[i]; cnt1=1; }
        else if (cnt2==0) { c2=nums[i]; cnt2=1; }
        else { cnt1--; cnt2--; }
    }
    int fc1=0, fc2=0, threshold=n/3;
    for (int i=0;i<n;i++) { if(nums[i]==c1) fc1++; else if(nums[i]==c2) fc2++; }
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;  // write through pointer
    if (fc1 > threshold) res[(*returnSize)++] = c1;
    if (fc2 > threshold) res[(*returnSize)++] = c2;
    return res;
}
