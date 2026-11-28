# problem title : Reverse Integer
# Solve the stated task using standard input and standard output.
class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        rev = int(str(abs(x))[::-1]) * sign
        if rev < -2**31 or rev > 2**31 - 1:
            return 0
        return rev
