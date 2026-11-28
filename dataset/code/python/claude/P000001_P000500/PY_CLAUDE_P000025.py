
class Solution:
    def reverseNumber(self, n: int) -> int:
        sign = -1 if n < 0 else 1
        n = abs(n)
        rev = 0
        while n > 0:
            rev = rev * 10 + n % 10
            n //= 10
        return sign * rev
