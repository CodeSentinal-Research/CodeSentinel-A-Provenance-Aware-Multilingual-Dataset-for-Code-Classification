from typing import List

class Solution:
    def areIdentical(self, mat1: List[List[int]], mat2: List[List[int]]) -> bool:
        if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
            return False
        for i in range(len(mat1)):
            for j in range(len(mat1[0])):
                if mat1[i][j] != mat2[i][j]:
                    return False
        return True