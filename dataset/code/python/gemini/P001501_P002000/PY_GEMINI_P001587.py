class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        last = {'a': -1, 'b': -1, 'c': -1}
        ans = 0
        for i, c in enumerate(s):
            last[c] = i
            ans += 1 + min(last.values())
        return ans