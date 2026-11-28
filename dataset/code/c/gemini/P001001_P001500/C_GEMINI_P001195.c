#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maxAlternatingSum(int* nums, int numsSize) {
    long long even = 0, odd = 0;
    for (int i = 0; i < numsSize; i++) {
        long long x = nums[i];
        even = MAX(even, odd + x);
        odd = MAX(odd, even - x);
    }
    return even;
}