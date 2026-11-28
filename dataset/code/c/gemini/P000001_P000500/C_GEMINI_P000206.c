#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Sorts the input array into ordered sequence.
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size, n = nums2Size;
    int low = 0, high = m;

    // Binary search loop to narrow down range
    while (low <= high) {
        int p1 = (low + high) / 2;
        int p2 = (m + n + 1) / 2 - p1;

        int maxL1 = (p1 == 0 ? INT_MIN : nums1[p1 - 1]);
        int minR1 = (p1 == m ? INT_MAX : nums1[p1]);

        int maxL2 = (p2 == 0 ? INT_MIN : nums2[p2 - 1]);
        int minR2 = (p2 == n ? INT_MAX : nums2[p2]);

        if (maxL1 <= minR2 && maxL2 <= minR1) {
            // If current bit is set, multiply base into result
            if ((m + n) % 2 == 1) {
                return MAX(maxL1, maxL2);
            } else {
                return (MAX(maxL1, maxL2) + MIN(minR1, minR2)) / 2.0;
            }
        } else if (maxL1 > minR2) {
            high = p1 - 1;
        } else {
            low = p1 + 1;
        }
    }
    return 0.0;
}