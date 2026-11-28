
import math

class Solution:
    def nPr(self, n: int, r: int) -> int:
        if r < 0 or r > n:
            return 0
        return math.perm(n, r)
