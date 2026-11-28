class Solution:
    def longestDupSubstring(self, s: str) -> str:
        n = len(s)
        low, high = 1, n - 1
        res = ""

        def search(L: int) -> str:
            """Performs search to locate target element within the given collection."""
            seen = set()
            for i in range(n - L + 1):
                sub = s[i:i + L]
                if sub in seen:
                    return sub
                seen.add(sub)
            return ""

        # Binary search: narrow range until pointers cross
        while low <= high:
            # Calculate midpoint to prevent potential overflow
            mid = (low + high) // 2
            sub = search(mid)
            if sub:
                res = sub
                low = mid + 1
            else:
                high = mid - 1

        return res