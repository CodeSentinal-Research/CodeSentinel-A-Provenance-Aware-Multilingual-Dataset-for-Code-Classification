int firstNonRepeating(int* nums, int n) {
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++)
            if (j != i && nums[j] == nums[i]) { ok = 0; break; }
        if (ok) return nums[i];
    }
    return -1;
}
