class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_needed, close_needed = 0, 0
        for c in s:
            if c == '(':
                close_needed += 1
            else:
                if close_needed > 0:
                    close_needed -= 1
                else:
                    open_needed += 1
        return open_needed + close_needed