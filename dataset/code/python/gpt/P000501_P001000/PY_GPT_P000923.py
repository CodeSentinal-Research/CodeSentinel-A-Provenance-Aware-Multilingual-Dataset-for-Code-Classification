# problem title : Count Numbers with Unique Digits
# Solve the stated task using standard input and standard output.
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        ans = 10
        unique_digits = 9
        available = 9
        for i in range(2, min(n + 1, 11)):
            unique_digits *= available
            ans += unique_digits
            available -= 1
        return ans
