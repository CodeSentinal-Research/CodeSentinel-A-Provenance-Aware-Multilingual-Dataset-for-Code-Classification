# problem title : Complement of Base 10 Integer
# Solve the stated task using standard input and standard output.
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        mask = (1 << n.bit_length()) - 1
        return n ^ mask
