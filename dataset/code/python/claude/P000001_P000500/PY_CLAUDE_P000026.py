
class Solution:
    def isPalindrome(self, n: int) -> bool:
        if n < 0:
            return False
        s = str(n)
        return s == s[::-1]
