
class Solution:
    def checkSign(self, n: int) -> str:
        if n > 0:
            return "Positive"
        elif n < 0:
            return "Negative"
        return "Zero"
