from typing import List

class Solution:
    def maximumSumRectangle(self, R: int, C: int, M: List[List[int]]) -> int:
        max_sum = float('-inf')

        for l in range(C):
            temp = [0] * R
            for r in range(l, C):
                for i in range(R):
                    temp[i] += M[i][r]

                # Kadane's algorithm on temp
                cur = max_so_far = temp[0]
                for x in temp[1:]:
                    cur = max(x, cur + x)
                    max_so_far = max(max_so_far, cur)

                max_sum = max(max_sum, max_so_far)

        return max_sum