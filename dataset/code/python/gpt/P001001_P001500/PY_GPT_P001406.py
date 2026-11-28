# problem title : Most Frequent Number Following Key
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        count = Counter(nums[i + 1] for i in range(len(nums) - 1) if nums[i] == key)
        return count.most_common(1)[0][0]
