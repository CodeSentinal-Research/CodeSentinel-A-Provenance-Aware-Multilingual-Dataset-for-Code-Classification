# problem title : Clone an Undirected Graph
# Solve the stated task using standard input and standard output.
from typing import Optional

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        cloned = {}

        def dfs(curr: 'Node') -> 'Node':
            if curr in cloned:
                return cloned[curr]
            copy = Node(curr.val)
            cloned[curr] = copy
            for nbr in curr.neighbors:
                copy.neighbors.append(dfs(nbr))
            return copy

        return dfs(node)
