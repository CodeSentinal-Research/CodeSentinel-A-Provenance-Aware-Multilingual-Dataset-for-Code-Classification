#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getMaxLen(int* nums, int numsSize) {
    int pos = 0, neg = 0, ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (x == 0) {
            pos = 0;
            neg = 0;
        } else if (x > 0) {
            pos++;
            neg = (neg > 0 ? neg + 1 : 0);
        } else {
            int newPos = (neg > 0 ? neg + 1 : 0);
            int newNeg = pos + 1;
            pos = newPos;
            neg = newNeg;
        }
        ans = MAX(ans, pos);
    }
    return ans;
}