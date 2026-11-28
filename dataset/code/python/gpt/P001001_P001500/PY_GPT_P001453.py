# problem title : Longest Consecutive Character Run
# Solve the stated task using standard input and standard output.
class Solution:
    def maxPower(self, s: str) -> int:
        max_run = 1
        cur_run = 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cur_run += 1
                max_run = max(max_run, cur_run)
            else:
                cur_run = 1
        return max_run
