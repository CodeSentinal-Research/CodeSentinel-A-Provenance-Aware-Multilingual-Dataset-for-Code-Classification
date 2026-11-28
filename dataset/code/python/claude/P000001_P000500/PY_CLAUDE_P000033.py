
class Solution:
    def sumEvenNumbers(self, n: int) -> int:
        if n < 2:
            return 0
        k = n // 2
        return k * (k + 1)
