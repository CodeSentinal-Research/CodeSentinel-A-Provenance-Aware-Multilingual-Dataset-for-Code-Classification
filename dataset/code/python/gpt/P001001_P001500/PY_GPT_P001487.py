# problem title : Camelcase Matching
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def match(q: str) -> bool:
            j = 0
            for c in q:
                if j < len(pattern) and c == pattern[j]:
                    j += 1
                elif c.isupper():
                    return False
            return j == len(pattern)

        return [match(q) for q in queries]
