
class Solution:
    def compoundInterest(self, principal: float, rate: float, time: float) -> float:
        amount = principal * ((1.0 + rate / 100.0) ** time)
        return amount - principal
