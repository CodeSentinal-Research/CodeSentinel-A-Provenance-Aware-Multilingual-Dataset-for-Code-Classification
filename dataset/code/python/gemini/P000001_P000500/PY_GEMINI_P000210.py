from typing import List

class Solution:
    def commonElements(self, A: List[int], B: List[int], C: List[int]) -> List[int]:
        i = j = k = 0
        res = []

        while i < len(A) and j < len(B) and k < len(C):
            if A[i] == B[j] == C[k]:
                if not res or res[-1] != A[i]:
                    res.append(A[i])
                i += 1
                j += 1
                k += 1
            elif A[i] < B[j]:
                i += 1
            elif B[j] < C[k]:
                j += 1
            else:
                k += 1

        return res