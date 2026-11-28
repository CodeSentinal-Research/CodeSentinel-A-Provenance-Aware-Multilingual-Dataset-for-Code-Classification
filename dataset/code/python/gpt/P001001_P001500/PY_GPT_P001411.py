# problem title : Find Players With Zero or One Loss
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses = Counter()
        players = set()

        for w, l in matches:
            players.add(w)
            players.add(l)
            losses[l] += 1

        zero_loss = sorted(p for p in players if losses[p] == 0)
        one_loss = sorted(p for p in players if losses[p] == 1)
        return [zero_loss, one_loss]
