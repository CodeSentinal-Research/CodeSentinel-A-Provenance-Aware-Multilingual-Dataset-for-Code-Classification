# problem title : Top K Frequent Elements
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        return [item[0] for item in count.most_common(k)]
