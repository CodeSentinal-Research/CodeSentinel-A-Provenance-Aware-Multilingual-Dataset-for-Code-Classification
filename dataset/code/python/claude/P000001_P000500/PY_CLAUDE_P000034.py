
class Solution:
    def sumOddNumbers(self, n: int) -> int:
        if n < 1:
            return 0
        k = (n + 1) // 2
        return k * k
