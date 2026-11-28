# problem title : Integer Break
# Solve the stated task using standard input and standard output.
class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
        prod = 1
        while n > 4:
            prod *= 3
            n -= 3
        return prod * n
