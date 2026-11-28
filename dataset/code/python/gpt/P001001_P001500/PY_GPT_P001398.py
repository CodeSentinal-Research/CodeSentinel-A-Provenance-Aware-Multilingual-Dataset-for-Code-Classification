# problem title : Find Common Characters
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        common = Counter(words[0])
        for w in words[1:]:
            common &= Counter(w)
        return list(common.elements())
