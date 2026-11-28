from typing import List

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        max_xor = 0
        mask = 0
        for i in range(31, -1, -1):
            mask |= (1 << i)
            prefixes = {num & mask for num in nums}
            greedy_target = max_xor | (1 << i)
            for p in prefixes:
                if (p ^ greedy_target) in prefixes:
                    max_xor = greedy_target
                    break
        return max_xor