
class Solution:
    def isDivisible(self, a: int, b: int) -> bool:
        if b == 0:
            return False
        return a % b == 0
