# The knows API is defined for you.
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int, knows) -> int:
        cand = 0
        for i in range(1, n):
            if knows(cand, i):
                cand = i

        for i in range(n):
            if i != cand:
                if knows(cand, i) or not knows(i, cand):
                    return -1
        return cand