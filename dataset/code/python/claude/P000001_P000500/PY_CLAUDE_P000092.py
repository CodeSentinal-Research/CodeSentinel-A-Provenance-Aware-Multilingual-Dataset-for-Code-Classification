
class Solution:
    def sumOfAP(self, a: float, d: float, n: int) -> float:
        return (n / 2.0) * (2 * a + (n - 1) * d)
