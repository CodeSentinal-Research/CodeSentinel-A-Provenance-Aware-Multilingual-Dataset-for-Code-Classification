from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        """Sorts the input array into ordered sequence."""
        n = len(arr)
        min_right = [0] * n
        min_right[-1] = arr[-1]

        for i in range(n - 2, -1, -1):
            min_right[i] = min(arr[i], min_right[i + 1])

        max_left = 0
        chunks = 1

        for i in range(n - 1):
            max_left = max(max_left, arr[i])
            if max_left <= min_right[i + 1]:
                chunks += 1

        return chunks