# problem title : Append Characters to String to Make Subsequence
# Solve the stated task using standard input and standard output.
class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        j = 0
        for c in s:
            if j < len(t) and c == t[j]:
                j += 1
        return len(t) - j
