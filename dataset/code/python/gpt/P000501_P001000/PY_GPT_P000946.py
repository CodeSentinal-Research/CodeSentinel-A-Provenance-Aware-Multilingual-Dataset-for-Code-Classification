# problem title : Flip Game II
# Solve the stated task using standard input and standard output.
class Solution:
    def canWin(self, currentState: str) -> bool:
        memo = {}
        def helper(s: str) -> bool:
            if s in memo:
                return memo[s]
            for i in range(len(s) - 1):
                if s[i:i+2] == "++":
                    next_s = s[:i] + "--" + s[i+2:]
                    if not helper(next_s):
                        memo[s] = True
                        return True
            memo[s] = False
            return False
        return helper(currentState)
