# problem title : Number Complement
# Solve the stated task using standard input and standard output.
class Solution:
    def findComplement(self, num: int) -> int:
        mask = (1 << num.bit_length()) - 1
        return num ^ mask
