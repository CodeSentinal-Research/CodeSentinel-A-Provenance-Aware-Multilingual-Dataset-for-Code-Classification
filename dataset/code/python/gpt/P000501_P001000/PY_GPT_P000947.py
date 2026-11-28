# problem title : Can I Win
# Solve the stated task using standard input and standard output.
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if desiredTotal <= 0:
            return True
        total = (maxChoosableInteger * (maxChoosableInteger + 1)) // 2
        if total < desiredTotal:
            return False

        memo = {}
        def helper(mask: int, current_total: int) -> bool:
            if mask in memo:
                return memo[mask]
            for i in range(1, maxChoosableInteger + 1):
                if not (mask & (1 << i)):
                    if current_total + i >= desiredTotal or not helper(mask | (1 << i), current_total + i):
                        memo[mask] = True
                        return True
            memo[mask] = False
            return False

        return helper(0, 0)
