from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        """Sorts the input array into ordered sequence."""
        rank = {val: i for i, val in enumerate(arr2)}
        return sorted(arr1, key=lambda x: (rank.get(x, 1000 + x), x))