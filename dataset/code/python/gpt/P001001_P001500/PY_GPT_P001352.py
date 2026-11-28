# problem title : Split String into Descending Consecutive Values
# Solve the stated task using standard input and standard output.
class Solution:
    def splitString(self, s: str) -> bool:
        def backtrack(idx: int, prev: int, count: int) -> bool:
            if idx == len(s):
                return count >= 2
            for i in range(idx + 1, len(s) + 1):
                val = int(s[idx:i])
                if prev == -1 or val == prev - 1:
                    if backtrack(i, val, count + 1):
                        return True
            return False

        return backtrack(0, -1, 0)
