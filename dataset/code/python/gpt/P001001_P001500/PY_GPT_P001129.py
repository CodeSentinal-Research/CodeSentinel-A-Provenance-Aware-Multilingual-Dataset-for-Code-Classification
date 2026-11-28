# problem title : Remove Maximum Number of Edges While Keeping Graph Fully Traversable
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        def find(parent, i):
            if parent[i] == i: return i
            parent[i] = find(parent, parent[i])
            return parent[i]

        parentA = list(range(n + 1))
        parentB = list(range(n + 1))
        used = 0
        edgesA = 0
        edgesB = 0

        # Type 3
        for type_, u, v in edges:
            if type_ == 3:
                rA1, rA2 = find(parentA, u), find(parentA, v)
                rB1, rB2 = find(parentB, u), find(parentB, v)
                if rA1 != rA2 or rB1 != rB2:
                    parentA[rA1] = rA2
                    parentB[rB1] = rB2
                    used += 1
                    edgesA += 1
                    edgesB += 1

        # Type 1 & 2
        for type_, u, v in edges:
            if type_ == 1:
                r1, r2 = find(parentA, u), find(parentA, v)
                if r1 != r2:
                    parentA[r1] = r2
                    used += 1
                    edgesA += 1
            elif type_ == 2:
                r1, r2 = find(parentB, u), find(parentB, v)
                if r1 != r2:
                    parentB[r1] = r2
                    used += 1
                    edgesB += 1

        if edgesA == n - 1 and edgesB == n - 1:
            return len(edges) - used
        return -1
