
from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        order = {v: i for i, v in enumerate(arr2)}
        in_arr2 = [x for x in arr1 if x in order]
        not_in = sorted(x for x in arr1 if x not in order)
        return sorted(in_arr2, key=lambda x: order[x]) + not_in
