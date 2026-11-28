
import math

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num < 0:
            return False
        r = int(math.isqrt(num))
        return r * r == num
