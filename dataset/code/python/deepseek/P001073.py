Here is a Python solution using Kruskal's algorithm. Kruskal's algorithm is a minimum spanning tree algorithm that finds the minimum weight of a spanning tree. It works by building the spanning tree one edge at a time, starting with the smallest possible edge.

class UnionFind:
    def __init__(self, N):
        self.p = list(range(N))
        self.rank = [0] * N

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if rx != ry:
            self.p[rx] = ry
            if self.rank[rx] < self.rank[ry]:
                self.p[ry] = rx
            else:
                self.p[rx] = ry
                if self.rank[ry] == self.rank[rx]:
                    self.rank[ry] += 1

def solve(N, M, edges):
    edges.sort(key=lambda x: x[2])

    uf = UnionFind(N)
    weight = 0
    for u, v, w in edges:
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            weight += w

    return weight

def main():
    N, M = map(int, input().split())
    edges = []

    for _ in range(M):
        u, v, w = map(int, input().split())
        edges.append((u-1, v-1, w))

    print(solve(N, M, edges))

main()

This program first reads the number of vertices and edges from the standard input, then it reads the edges and appends them to a list. The list is sorted by weight in ascending order. Then, for each edge, if the two vertices of the edge are not connected by a cycle in the union-find data structure, the union operation is performed and the weight of the edge is added to the total weight. The result is the total weight of the minimum spanning tree.