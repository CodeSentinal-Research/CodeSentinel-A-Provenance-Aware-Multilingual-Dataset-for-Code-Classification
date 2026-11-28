# problem title : Top K Frequent Elements
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        return [item[0] for item in heapq.nlargest(k, count.items(), key=lambda x: x[1])]
