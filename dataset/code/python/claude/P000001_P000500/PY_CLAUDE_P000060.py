
class Solution:
    def countEvenDigits(self, n: int) -> int:
        n = abs(n)
        if n == 0:
            return 1
        count = 0
        while n > 0:
            if (n % 10) % 2 == 0:
                count += 1
            n //= 10
        return count
