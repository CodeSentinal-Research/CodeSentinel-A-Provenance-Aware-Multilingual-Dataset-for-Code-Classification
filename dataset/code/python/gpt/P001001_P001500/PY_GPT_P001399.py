# problem title : Uncommon Words from Two Sentences
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        count = Counter((s1 + " " + s2).split())
        return [w for w, cnt in count.items() if cnt == 1]
