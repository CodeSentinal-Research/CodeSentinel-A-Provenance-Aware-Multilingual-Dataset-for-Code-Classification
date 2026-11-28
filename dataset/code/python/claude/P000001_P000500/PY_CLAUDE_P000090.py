
import math

class Solution:
    def nCr(self, n: int, r: int) -> int:
        if r < 0 or r > n:
            return 0
        return math.comb(n, r)
