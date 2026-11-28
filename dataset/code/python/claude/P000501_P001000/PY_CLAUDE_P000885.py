
class Solution:
    def isArmstrong(self, n: int) -> bool:
        digits = str(n)
        power = len(digits)
        return sum(int(d) ** power for d in digits) == n
