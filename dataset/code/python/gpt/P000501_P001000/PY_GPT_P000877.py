# problem title : Minimum Bit Flips to Convert Number
# Solve the stated task using standard input and standard output.
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        return bin(start ^ goal).count('1')
