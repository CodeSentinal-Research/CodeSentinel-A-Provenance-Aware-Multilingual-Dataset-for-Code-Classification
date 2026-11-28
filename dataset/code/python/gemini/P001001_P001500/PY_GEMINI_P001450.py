from typing import List

class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        rank = {c: [0] * n + [c] for c in votes[0]}

        for v in votes:
            for i, c in enumerate(v):
                rank[c][i] -= 1

        return "".join(sorted(votes[0], key=lambda c: rank[c]))