# problem title : Split Into Maximum Number of Unique Substrings
# Solve the stated task using standard input and standard output.
class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        seen = set()

        def backtrack(idx: int) -> int:
            if idx == len(s):
                return 0
            max_count = 0
            for i in range(idx + 1, len(s) + 1):
                sub = s[idx:i]
                if sub not in seen:
                    seen.add(sub)
                    max_count = max(max_count, 1 + backtrack(i))
                    seen.remove(sub)
            return max_count

        return backtrack(0)
