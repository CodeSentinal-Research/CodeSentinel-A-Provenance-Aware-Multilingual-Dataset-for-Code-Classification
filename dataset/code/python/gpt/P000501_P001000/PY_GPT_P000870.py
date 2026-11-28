# problem title : Sum of Two Integers Without Arithmetic Operators
# Solve the stated task using standard input and standard output.
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        max_int = 0x7FFFFFFF
        while b != 0:
            carry = ((a & b) << 1) & mask
            a = (a ^ b) & mask
            b = carry
        return a if a <= max_int else ~(a ^ mask)
