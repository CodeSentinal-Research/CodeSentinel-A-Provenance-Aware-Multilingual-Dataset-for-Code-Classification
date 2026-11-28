
class Solution:
    def isSpy(self, n: int) -> bool:
        digits = [int(c) for c in str(abs(n))]
        prod = 1
        for d in digits:
            prod *= d
        return sum(digits) == prod
