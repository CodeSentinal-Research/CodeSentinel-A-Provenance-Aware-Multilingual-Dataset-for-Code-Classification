# problem title : Minimum Length After Deleting Similar Ends
# Solve the stated task using standard input and standard output.
class Solution:
    def minimumLength(self, s: str) -> int:
        l, r = 0, len(s) - 1
        while l < r and s[l] == s[r]:
            c = s[l]
            while l <= r and s[l] == c:
                l += 1
            while l <= r and s[r] == c:
                r -= 1
        return r - l + 1
