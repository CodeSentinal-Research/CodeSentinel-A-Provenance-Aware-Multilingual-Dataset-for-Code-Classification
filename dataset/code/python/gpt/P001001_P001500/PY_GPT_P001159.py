# problem title : Decode Ways
# Solve the stated task using standard input and standard output.
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        n = len(s)
        a, b = 1, 1
        for i in range(1, n):
            c = 0
            if s[i] != '0':
                c += b
            if 10 <= int(s[i-1:i+1]) <= 26:
                c += a
            a, b = b, c
        return b
