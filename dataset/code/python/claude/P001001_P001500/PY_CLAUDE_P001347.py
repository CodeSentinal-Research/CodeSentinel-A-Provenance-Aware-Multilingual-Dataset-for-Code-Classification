
class Solution:
    def calculate(self, a: float, op: str, b: float) -> float:
        if op == '+':
            return a + b
        elif op == '-':
            return a - b
        elif op == '*':
            return a * b
        elif op == '/':
            return a / b if b != 0 else float('inf')
        return 0
