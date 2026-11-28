
from typing import List

class Solution:
    def fibonacciSeries(self, n: int) -> List[int]:
        if n <= 0:
            return []
        if n == 1:
            return [0]
        res = [0, 1]
        for i in range(2, n):
            res.append(res[-1] + res[-2])
        return res
