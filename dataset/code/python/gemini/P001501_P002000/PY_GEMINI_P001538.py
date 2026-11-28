from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2 = len(s1), len(s2)
        if n1 > n2:
            return False

        c1, c2 = Counter(s1), Counter(s2[:n1])
        if c1 == c2:
            return True

        for i in range(n1, n2):
            c2[s2[i]] += 1
            c2[s2[i - n1]] -= 1
            if c2[s2[i - n1]] == 0:
                del c2[s2[i - n1]]
            if c1 == c2:
                return True

        return False