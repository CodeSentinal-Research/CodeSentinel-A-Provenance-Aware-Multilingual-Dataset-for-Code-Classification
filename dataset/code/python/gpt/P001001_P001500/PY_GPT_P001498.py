# problem title : Separate Black and White Balls
# Solve the stated task using standard input and standard output.
class Solution:
    def minimumSteps(self, s: str) -> int:
        ans = 0
        ones = 0
        for c in s:
            if c == '1':
                ones += 1
            else:
                ans += ones
        return ans
