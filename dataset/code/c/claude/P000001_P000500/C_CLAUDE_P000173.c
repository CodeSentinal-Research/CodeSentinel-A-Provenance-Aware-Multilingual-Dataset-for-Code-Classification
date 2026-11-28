#include <limits.h>
int maxDifference(int* nums, int n) {
    int minVal = nums[0], maxDiff = INT_MIN;
    for (int i=1;i<n;i++) {
        int d = nums[i]-minVal;
        if(d>maxDiff) maxDiff=d;
        if(nums[i]<minVal) minVal=nums[i];
    }
    return maxDiff;
}
