# problem title : Palindrome Number
# Solve the stated task using standard input and standard output.
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        return str(x) == str(x)[::-1]
