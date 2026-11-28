#include <stdlib.h>

#define MOD 1000000007LL

void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        minHeapify(heap, n, smallest);
    }
}

int maximumProduct(int* nums, int numsSize, int k) {
    for (int i = numsSize / 2 - 1; i >= 0; i--) minHeapify(nums, numsSize, i);

    for (int i = 0; i < k; i++) {
        nums[0]++;
        minHeapify(nums, numsSize, 0);
    }

    long long res = 1;
    for (int i = 0; i < numsSize; i++) {
        res = (res * nums[i]) % MOD;
    }
    return (int)res;
}