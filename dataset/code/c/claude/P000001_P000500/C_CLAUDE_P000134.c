void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }
int* sortArrayByParity(int* nums, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        while (l < r && nums[l] % 2 == 0) l++;
        while (l < r && nums[r] % 2 != 0) r--;
        if (l < r) swap(&nums[l], &nums[r]);
    }
    return nums;
}
