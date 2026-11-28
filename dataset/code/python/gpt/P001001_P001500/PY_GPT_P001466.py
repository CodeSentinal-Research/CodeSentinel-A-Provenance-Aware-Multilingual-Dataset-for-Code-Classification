# problem title : Valid Palindrome
# Solve the stated task using standard input and standard output.
class Solution:
    def isPalindrome(self, s: str) -> bool:
        filtered = [c.lower() for c in s if c.isalnum()]
        return filtered == filtered[::-1]
