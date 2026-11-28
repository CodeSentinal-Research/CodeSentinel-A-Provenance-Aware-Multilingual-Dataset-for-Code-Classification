"""
343. Integer Break (Medium)
Pattern: Math / Dynamic Programming

--------------------------------------------------------------------------------
PROBLEM UNDERSTANDING
--------------------------------------------------------------------------------
Given integer n. Break it into sum of k positive integers (k >= 2).
Maximize the product of those integers.

Input: n = 10
Output: 36 (10 = 3 + 3 + 4, 3*3*4 = 36)

--------------------------------------------------------------------------------
INTUITION: MATH (POWER OF 3)
--------------------------------------------------------------------------------
Mathematically, to maximize the product, we should break the number into
parts that are as close to 'e' (2.718...) as possible.
The closest integers to 'e' are 2 and 3.
3 is better than 2 (3*3 = 9 > 2*2*2 = 8, for sum 6).

Rule of Thumb:
- Use as many 3s as possible.
- Avoid 1s (useless for product).
- If remainder is 1, borrow a 3 to make 4 (2*2), because 4 > 3*1.
- If remainder is 2, keep it (2 > 1).

Cases for N:
- If n % 3 == 0: 3^(n/3)
- If n % 3 == 1: 3^(n/3 - 1) * 4  (e.g., 4 -> 2*2=4, not 3*1=3)
- If n % 3 == 2: 3^(n/3) * 2

Edge Cases: n=2 -> 1 (1+1), n=3 -> 2 (1+2).

--------------------------------------------------------------------------------
ALGORITHM
--------------------------------------------------------------------------------
1. Handle n=2, n=3 separately.
2. Calculate quotient `q = n // 3` and remainder `r = n % 3`.
3. If r == 0: return 3^q.
4. If r == 1: return 3^(q-1) * 4.
5. If r == 2: return 3^q * 2.

--------------------------------------------------------------------------------
"""

class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
            
        quotient = n // 3
        remainder = n % 3
        
        if remainder == 0:
            return 3 ** quotient
        elif remainder == 1:
            # 3^(q-1) * 4  (borrow one 3 to add to 1, making 4)
            return (3 ** (quotient - 1)) * 4
        else: # remainder == 2
            return (3 ** quotient) * 2

if __name__ == "__main__":
    sol = Solution()
    print(f"n=2: {sol.integerBreak(2)}")   # 1
    print(f"n=10: {sol.integerBreak(10)}") # 36
    print(f"n=8: {sol.integerBreak(8)}")   # 3+3+2 -> 18
