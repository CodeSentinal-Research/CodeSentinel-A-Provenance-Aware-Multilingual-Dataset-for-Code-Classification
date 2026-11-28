from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """Sorts the input array into ordered sequence."""
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        low, high = 0, m

        # Binary search: narrow range until pointers cross
        while low <= high:
            p1 = (low + high) // 2
            p2 = (m + n + 1) // 2 - p1

            max_l1 = float('-inf') if p1 == 0 else nums1[p1 - 1]
            min_r1 = float('inf') if p1 == m else nums1[p1]

            max_l2 = float('-inf') if p2 == 0 else nums2[p2 - 1]
            min_r2 = float('inf') if p2 == n else nums2[p2]

            if max_l1 <= min_r2 and max_l2 <= min_r1:
                # If current bit is set, multiply base into result
                if (m + n) % 2 == 1:
                    return max(max_l1, max_l2)
                else:
                    return (max(max_l1, max_l2) + min(min_r1, min_r2)) / 2.0
            elif max_l1 > min_r2:
                high = p1 - 1
            else:
                low = p1 + 1

        return 0.0