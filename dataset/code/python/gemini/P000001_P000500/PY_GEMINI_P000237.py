from typing import List

class Solution:
    def rotateMatrix(self, N: int, M: int, K: int, Mat: List[List[int]]) -> List[List[int]]:
        k = K % M
        for i in range(N):
            Mat[i] = Mat[i][k:] + Mat[i][:k]
        return Mat