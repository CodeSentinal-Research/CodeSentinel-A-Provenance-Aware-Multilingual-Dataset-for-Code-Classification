
from typing import List

class Solution:
    def primesInRange(self, low: int, high: int) -> List[int]:
        if high < 2:
            return []
        is_prime = [True] * (high + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(high**0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, high + 1, i):
                    is_prime[j] = False
        return [i for i in range(max(2, low), high + 1) if is_prime[i]]
