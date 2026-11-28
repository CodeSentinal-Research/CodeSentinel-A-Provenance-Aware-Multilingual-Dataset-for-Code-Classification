class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = {}
        l = max_len = 0
        for r, c in enumerate(s):
            if c in last and last[c] >= l:
                l = last[c] + 1
            last[c] = r
            max_len = max(max_len, r - l + 1)
        return max_len