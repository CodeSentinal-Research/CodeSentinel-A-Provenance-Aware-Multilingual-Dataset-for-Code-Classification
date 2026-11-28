# problem title : Hamming Distance
# Solve the stated task using standard input and standard output.
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')
