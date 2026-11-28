# problem title : Find the Kth Largest Element
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]
