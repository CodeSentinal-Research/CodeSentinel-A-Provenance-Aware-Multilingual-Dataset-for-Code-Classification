# problem title : Valid Anagram
# Solve the stated task using standard input and standard output.
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
