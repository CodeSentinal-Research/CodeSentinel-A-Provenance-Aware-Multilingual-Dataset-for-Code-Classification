# problem title : Put Marbles in Bags
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        if k == 1 or k == n:
            return 0

        pair_weights = sorted(weights[i] + weights[i + 1] for i in range(n - 1))
        min_sum = sum(pair_weights[:k - 1])
        max_sum = sum(pair_weights[-(k - 1):])
        return max_sum - min_sum
