# problem title : Nim Game Winner
# Solve the stated task using standard input and standard output.
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n % 4 != 0
