from typing import List

class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def max_single(nums: List[int], count: int) -> List[int]:
            drop = len(nums) - count
            stack = []
            for x in nums:
                while drop > 0 and stack and stack[-1] < x:
                    stack.pop()
                    drop -= 1
                stack.append(x)
            return stack[:count]

        def merge(a: List[int], b: List[int]) -> List[int]:
            return [max(a, b).pop(0) for _ in range(len(a) + len(b))]

        ans = []
        for i in range(max(0, k - len(nums2)), min(k, len(nums1)) + 1):
            sub1 = max_single(nums1, i)
            sub2 = max_single(nums2, k - i)
            cand = merge(sub1, sub2)
            ans = max(ans, cand)

        return ans