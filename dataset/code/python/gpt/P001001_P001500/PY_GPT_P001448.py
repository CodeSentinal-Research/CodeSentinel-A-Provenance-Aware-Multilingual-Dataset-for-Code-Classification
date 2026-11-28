# problem title : Verify Alien Dictionary
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_map = {c: i for i, c in enumerate(order)}

        def is_sorted(w1: str, w2: str) -> bool:
            for c1, c2 in zip(w1, w2):
                if order_map[c1] < order_map[c2]:
                    return True
                elif order_map[c1] > order_map[c2]:
                    return False
            return len(w1) <= len(w2)

        return all(is_sorted(words[i], words[i + 1]) for i in range(len(words) - 1))
