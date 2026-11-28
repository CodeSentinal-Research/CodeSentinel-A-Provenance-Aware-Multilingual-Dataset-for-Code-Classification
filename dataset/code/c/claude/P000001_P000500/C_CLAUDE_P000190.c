/* P000190: Find Duplicate in Array of N+1 Elements
 * Approach: index-marking (negate visited index values)
 * Different from P000137 which uses Floyd's cycle detection */
int findDuplicateInNPlusOne(int* nums, int n) {
    int duplicate = -1;
    for (int i = 0; i <= n; i++) {
        int idx = nums[i] < 0 ? -nums[i] : nums[i];
        if (nums[idx] < 0) {
            duplicate = idx;
            break;
        }
        nums[idx] = -nums[idx];
    }
    /* restore array */
    for (int i = 0; i <= n; i++)
        if (nums[i] < 0) nums[i] = -nums[i];
    return duplicate;
}
