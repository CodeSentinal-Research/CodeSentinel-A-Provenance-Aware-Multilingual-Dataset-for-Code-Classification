from collections import defaultdict
from typing import List

class Solution:
    def countDistinct(self, arr: List[int], k: int) -> List[int]:
        res = []
        freq = defaultdict(int)
        distinct = 0

        for i in range(k):
            if freq[arr[i]] == 0:
                distinct += 1
            freq[arr[i]] += 1
        res.append(distinct)

        for i in range(k, len(arr)):
            freq[arr[i - k]] -= 1
            if freq[arr[i - k]] == 0:
                distinct -= 1

            if freq[arr[i]] == 0:
                distinct += 1
            freq[arr[i]] += 1

            res.append(distinct)

        return res