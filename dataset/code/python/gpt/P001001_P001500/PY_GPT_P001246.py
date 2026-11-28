# problem title : Bag of Tokens
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        l, r = 0, len(tokens) - 1
        score, max_score = 0, 0

        while l <= r:
            if power >= tokens[l]:
                power -= tokens[l]
                score += 1
                l += 1
                max_score = max(max_score, score)
            elif score > 0:
                power += tokens[r]
                score -= 1
                r -= 1
            else:
                break

        return max_score
