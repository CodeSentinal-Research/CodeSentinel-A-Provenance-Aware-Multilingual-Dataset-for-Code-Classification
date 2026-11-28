
class Solution:
    def isHarshad(self, n: int) -> bool:
        if n <= 0:
            return False
        sum_digits = sum(int(c) for c in str(n))
        return n % sum_digits == 0
