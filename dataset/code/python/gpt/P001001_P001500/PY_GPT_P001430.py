# problem title : Find the Prefix Common Array of Two Arrays
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        res = [0] * n
        seen = set()
        common = 0

        for i in range(n):
            if A[i] in seen:
                common += 1
            else:
                seen.add(A[i])

            if B[i] in seen:
                common += 1
            else:
                seen.add(B[i])

            res[i] = common

        return res
