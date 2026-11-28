
class Solution:
    def sumEvenSeries(self, n: int) -> int:
        k = n // 2
        return k * (k + 1)
