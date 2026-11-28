# problem title : Broken Calculator
# Solve the stated task using standard input and standard output.
class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        ans = 0
        while target > startValue:
            ans += 1
            if target % 2 == 1:
                target += 1
            else:
                target //= 2
        return ans + startValue - target
