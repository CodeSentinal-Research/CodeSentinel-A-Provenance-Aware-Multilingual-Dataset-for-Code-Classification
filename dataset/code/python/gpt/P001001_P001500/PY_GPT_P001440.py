# problem title : Longest Word Through Deleting
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        def is_subseq(w: str) -> bool:
            it = iter(s)
            return all(c in it for c in w)

        best = ""
        for w in dictionary:
            if is_subseq(w):
                if len(w) > len(best) or (len(w) == len(best) and w < best):
                    best = w
        return best
