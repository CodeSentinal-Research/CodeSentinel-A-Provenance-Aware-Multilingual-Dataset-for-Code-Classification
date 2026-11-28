
from typing import List

class Solution:
    def getFactors(self, n: int) -> List[int]:
        if n <= 0:
            return []
        factors = []
        for i in range(1, int(n**0.5) + 1):
            if n % i == 0:
                factors.append(i)
                if i * i != n:
                    factors.append(n // i)
        return sorted(factors)
