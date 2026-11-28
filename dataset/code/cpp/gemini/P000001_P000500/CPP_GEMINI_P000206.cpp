#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
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
                    return std::max(maxL1, maxL2);
                } else {
                    return (std::max(maxL1, maxL2) + std::min(minR1, minR2)) / 2.0;
                }
            } else if (maxL1 > minR2) {
                high = p1 - 1;
            } else {
                low = p1 + 1;
            }
        }
        return 0.0;
    }
};