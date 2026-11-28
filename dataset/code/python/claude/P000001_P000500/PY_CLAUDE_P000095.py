
class Solution:
    def isNeon(self, n: int) -> bool:
        sq = n * n
        return sum(int(c) for c in str(sq)) == n
