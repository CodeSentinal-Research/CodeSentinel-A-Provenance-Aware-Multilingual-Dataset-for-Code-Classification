
class Solution:
    def productOfDigits(self, n: int) -> int:
        n = abs(n)
        if n == 0:
            return 0
        prod = 1
        while n > 0:
            prod *= (n % 10)
            n //= 10
        return prod
