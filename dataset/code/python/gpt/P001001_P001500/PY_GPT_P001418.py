# problem title : Count Number of Consistent Strings
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed_set = set(allowed)
        return sum(all(c in allowed_set for c in w) for w in words)
