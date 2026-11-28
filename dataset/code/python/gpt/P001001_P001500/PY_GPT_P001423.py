# problem title : Find and Replace Pattern
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def get_norm(s: str):
            seen = {}
            return [seen.setdefault(c, len(seen)) for c in s]

        pat_norm = get_norm(pattern)
        return [w for w in words if get_norm(w) == pat_norm]
