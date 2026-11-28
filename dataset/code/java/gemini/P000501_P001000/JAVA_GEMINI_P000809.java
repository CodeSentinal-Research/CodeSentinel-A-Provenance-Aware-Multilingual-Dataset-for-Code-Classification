public class Solution {
    // Performs search to locate target element within the given collection.
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}