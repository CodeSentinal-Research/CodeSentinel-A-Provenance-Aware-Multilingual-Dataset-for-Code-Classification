from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)
        max_freq = 0
        l = 0

        for r, c in enumerate(s):
            count[c] += 1
            max_freq = max(max_freq, count[c])
            if (r - l + 1) - max_freq > k:
                count[s[l]] -= 1
                l += 1

        return len(s) - l