# problem title : Number of Provinces
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        parent = list(range(n))
        def find(i):
            if parent[i] == i: return i
            parent[i] = find(parent[i])
            return parent[i]

        provinces = n
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j]:
                    ri, rj = find(i), find(j)
                    if ri != rj:
                        parent[ri] = rj
                        provinces -= 1
        return provinces
