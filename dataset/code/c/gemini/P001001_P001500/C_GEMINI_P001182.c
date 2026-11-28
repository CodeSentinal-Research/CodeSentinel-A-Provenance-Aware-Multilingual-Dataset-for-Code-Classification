#define MAX(a, b) ((a) > (b) ? (a) : (b))

int jump(int* nums, int numsSize) {
    int jumps = 0;
    int curEnd = 0, curFarthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        curFarthest = MAX(curFarthest, i + nums[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}