class Solution:
    def isSubsequence(self, A: str, B: str) -> bool:
        i = j = 0
        while i < len(A) and j < len(B):
            if A[i] == B[j]:
                i += 1
            j += 1
        return i == len(A)