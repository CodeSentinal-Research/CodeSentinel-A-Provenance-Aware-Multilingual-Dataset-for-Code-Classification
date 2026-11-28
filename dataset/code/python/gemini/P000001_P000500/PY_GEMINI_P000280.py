from collections import Counter

class Solution:
    def validAnagramAfterRemoval(self, s: str, t: str) -> bool:
        # Check if s can become an anagram of t by removing exactly one character from s
        if len(s) != len(t) + 1:
            return False
        freq_s = Counter(s)
        freq_t = Counter(t)

        diff_count = 0
        for char, count in freq_s.items():
            t_count = freq_t.get(char, 0)
            if count > t_count:
                diff_count += count - t_count
            elif count < t_count:
                return False

        return diff_count == 1