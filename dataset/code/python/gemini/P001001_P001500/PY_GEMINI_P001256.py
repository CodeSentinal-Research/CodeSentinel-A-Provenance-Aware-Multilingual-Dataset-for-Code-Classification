from collections import Counter

class Solution:
    def minDeletions(self, s: str) -> int:
        count = Counter(s)
        used_freq = set()
        deletions = 0

        for freq in count.values():
            while freq > 0 and freq in used_freq:
                freq -= 1
                deletions += 1
            used_freq.add(freq)

        return deletions