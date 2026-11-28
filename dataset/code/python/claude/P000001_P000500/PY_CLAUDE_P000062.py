
import math

class Solution:
    def isStrong(self, n: int) -> bool:
        if n <= 0:
            return False
        total = sum(math.factorial(int(c)) for c in str(n))
        return total == n
