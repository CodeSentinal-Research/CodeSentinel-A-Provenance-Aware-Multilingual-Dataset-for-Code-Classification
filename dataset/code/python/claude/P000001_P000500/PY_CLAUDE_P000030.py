
import math

class Solution:
    def lcm(self, a: int, b: int) -> int:
        return abs(a * b) // math.gcd(a, b) if a and b else 0
