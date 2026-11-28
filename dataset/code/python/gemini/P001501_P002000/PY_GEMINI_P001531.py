class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_pos = {}
        l = 0
        max_len = 0

        for r, c in enumerate(s):
            if c in last_pos and last_pos[c] >= l:
                l = last_pos[c] + 1
            last_pos[c] = r
            max_len = max(max_len, r - l + 1)

        return max_len