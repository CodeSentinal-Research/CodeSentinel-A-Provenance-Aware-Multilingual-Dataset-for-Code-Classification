void countEvenOdd(int* nums, int n, int* even, int* odd) {
    *even = 0;  // write through pointer
    for (int i = 0; i < n; i++) if (nums[i] % 2 == 0) (*even)++;
    *odd = n - *even;  // write through pointer
}
