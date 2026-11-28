
class Solution:
    def sumOfDigits(self, n: int) -> int:
        return sum(int(d) for d in str(abs(n)))
