public class Solution {
    // Sorts the input array into ordered sequence.
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length, n = nums2.length;
        int low = 0, high = m;

        // Binary search loop to narrow down range
        while (low <= high) {
            int p1 = (low + high) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int maxL1 = (p1 == 0 ? Integer.MIN_VALUE : nums1[p1 - 1]);
            int minR1 = (p1 == m ? Integer.MAX_VALUE : nums1[p1]);

            int maxL2 = (p2 == 0 ? Integer.MIN_VALUE : nums2[p2 - 1]);
            int minR2 = (p2 == n ? Integer.MAX_VALUE : nums2[p2]);

            if (maxL1 <= minR2 && maxL2 <= minR1) {
                // If current bit is set, multiply base into result
                if ((m + n) % 2 == 1) {
                    return Math.max(maxL1, maxL2);
                } else {
                    return (Math.max(maxL1, maxL2) + Math.min(minR1, minR2)) / 2.0;
                }
            } else if (maxL1 > minR2) {
                high = p1 - 1;
            } else {
                low = p1 + 1;
            }
        }
        return 0.0;
    }
}