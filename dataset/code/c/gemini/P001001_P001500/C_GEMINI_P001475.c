// Sorts the input array into ordered sequence.
void sortColors(int* nums, int numsSize) {
    int l = 0, curr = 0, r = numsSize - 1;
    while (curr <= r) {
        if (nums[curr] == 0) {
            int tmp = nums[l]; nums[l] = nums[curr]; nums[curr] = tmp;
            l++;
            curr++;
        } else if (nums[curr] == 2) {
            int tmp = nums[curr]; nums[curr] = nums[r]; nums[r] = tmp;
            r--;
        } else {
            curr++;
        }
    }
}