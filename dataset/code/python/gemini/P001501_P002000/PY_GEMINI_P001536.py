from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        target = Counter(t)
        required = len(target)
        window = {}
        formed = 0
        l = 0

        ans = float('inf'), None, None

        for r, c in enumerate(s):
            window[c] = window.get(c, 0) + 1
            if c in target and window[c] == target[c]:
                formed += 1

            while l <= r and formed == required:
                if r - l + 1 < ans[0]:
                    ans = (r - l + 1, l, r)

                char_left = s[l]
                window[char_left] -= 1
                if char_left in target and window[char_left] < target[char_left]:
                    formed -= 1
                l += 1

        return "" if ans[0] == float('inf') else s[ans[1]:ans[2] + 1]