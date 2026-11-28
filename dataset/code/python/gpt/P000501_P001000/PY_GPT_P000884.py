# problem title : Digital Root
# Solve the stated task using standard input and standard output.
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        return 9 if num % 9 == 0 else num % 9
