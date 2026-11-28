
import math

class Solution:
    def lcmOfThree(self, a: int, b: int, c: int) -> int:
        def lcm(x, y):
            return abs(x * y) // math.gcd(x, y) if x and y else 0
        return lcm(lcm(a, b), c)
