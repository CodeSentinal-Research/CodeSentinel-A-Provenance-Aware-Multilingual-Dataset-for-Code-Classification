
class Solution:
    def power(self, base: int, exp: int, mod: int) -> int:
        result = 1
        base %= mod
        while exp > 0:
            if exp & 1:
                result = result * base % mod
            base = base * base % mod
            exp >>= 1
        return result
