Here is a Python solution using the Union-Find data structure to check if the graph is a tree. The Union-Find data structure is a data structure that tracks a partition of a set into disjoint sets. It's often used for solving problems like finding connected components in a graph and merging disjoint sets.

class UnionFind:
    def __init__(self, vertices):
        self.p = list(range(vertices))
        self.rank = [0] * vertices

    def find(self, vertex):
        if self.p[vertex] != vertex:
            self.p[vertex] = self.find(self.p[vertex])
        return self.p[vertex]

    def union(self, vertex1, vertex2):
        root1 = self.find(vertex1)
        root2 = self.find(vertex2)
        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.p[root2] = root1
            else:
                self.p[root1] = root2
                if self.rank[root1] == self.rank[root2]:
                    self.rank[root2] += 1

def solve(n, m, edges):
    uf = UnionFind(n)
    for u, v in edges:
        uf.union(u, v)
    if len(set(uf.find(u) for u in range(n))) != 1:
        print("NO")
        return
    print("YES")
    return

n, m = map(int, input().split())
edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(m)]
solve(n, m, edges)
This code works by first initializing the UnionFind data structure with the number of vertices. Then, for each edge, it adds the two vertices to the same set (union) in the UnionFind data structure. If the graph forms a tree, the final set should contain one root, which means all vertices are connected to the root, and the UnionFind data structure should be a tree.