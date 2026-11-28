# problem title : Check If Array Pairs Are Divisible by K
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        rem_count = defaultdict(int)
        for x in arr:
            rem_count[x % k] += 1

        for r, cnt in rem_count.items():
            if r == 0:
                if cnt % 2 != 0:
                    return False
            elif 2 * r == k:
                if cnt % 2 != 0:
                    return False
            elif cnt != rem_count[(k - r) % k]:
                return False

        return True
