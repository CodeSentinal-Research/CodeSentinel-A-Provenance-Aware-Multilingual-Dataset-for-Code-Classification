#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxConsecutiveZeros(int* nums, int numsSize) {
    int maxZeros = 0, curZeros = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            curZeros++;
            maxZeros = MAX(maxZeros, curZeros);
        } else {
            curZeros = 0;
        }
    }
    return maxZeros;
}