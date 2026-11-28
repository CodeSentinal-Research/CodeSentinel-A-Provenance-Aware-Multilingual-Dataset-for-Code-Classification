#include <stdlib.h>
int* findTwoOddOccurrences(int* nums, int n, int* returnSize) {
    int xor = 0;
    for (int i=0;i<n;i++) xor ^= nums[i];
    int bit = xor & (-xor);
    int a=0, b=0;
    for (int i=0;i<n;i++) {
        if (nums[i]&bit) a^=nums[i];
        else b^=nums[i];
    }
    *returnSize=2;  // write through pointer
    int* res=(int*)malloc(2*sizeof(int));
    res[0]=a; res[1]=b; return res;
}
