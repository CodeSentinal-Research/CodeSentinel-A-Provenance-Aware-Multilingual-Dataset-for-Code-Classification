#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestUniqueNumber(int* nums, int numsSize) {
    int count[1005] = {0};
    for (int i = 0; i < numsSize; i++) count[nums[i]]++;

    int maxVal = -1;
    for (int x = 1000; x >= 0; x--) {
        if (count[x] == 1) {
            return x;
        }
    }
    return -1;
}