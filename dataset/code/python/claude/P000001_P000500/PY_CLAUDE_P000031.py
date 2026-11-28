
class Solution:
    def isArmstrong(self, n: int) -> bool:
        if n < 0:
            return False
        s = str(n)
        k = len(s)
        return sum(int(c) ** k for c in s) == n
