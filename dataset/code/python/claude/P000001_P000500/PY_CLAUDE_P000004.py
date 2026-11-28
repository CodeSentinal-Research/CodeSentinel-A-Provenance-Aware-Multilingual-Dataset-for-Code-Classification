
class Solution:
    def divide(self, a: int, b: int) -> float:
        if b == 0:
            raise ZeroDivisionError("Cannot divide by zero")
        return a / b
