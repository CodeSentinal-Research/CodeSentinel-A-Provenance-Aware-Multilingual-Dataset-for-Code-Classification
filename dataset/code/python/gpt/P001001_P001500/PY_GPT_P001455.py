# problem title : Longest Duplicate Substring
# Solve the stated task using standard input and standard output.
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        n = len(s)
        low, high = 1, n - 1
        res = ""

        def search(L: int) -> str:
            seen = set()
            for i in range(n - L + 1):
                sub = s[i:i + L]
                if sub in seen:
                    return sub
                seen.add(sub)
            return ""

        while low <= high:
            mid = (low + high) // 2
            sub = search(mid)
            if sub:
                res = sub
                low = mid + 1
            else:
                high = mid - 1

        return res
