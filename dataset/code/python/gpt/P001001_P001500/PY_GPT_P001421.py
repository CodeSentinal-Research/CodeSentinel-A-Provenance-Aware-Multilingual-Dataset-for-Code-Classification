# problem title : Minimum Index Sum of Two Lists
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        map1 = {s: i for i, s in enumerate(list1)}
        min_sum = float('inf')
        res = []

        for j, s in enumerate(list2):
            if s in map1:
                cur_sum = map1[s] + j
                if cur_sum < min_sum:
                    min_sum = cur_sum
                    res = [s]
                elif cur_sum == min_sum:
                    res.append(s)

        return res
