Here is a Python solution for the problem using the Union-Find data structure. The Union-Find data structure is a data structure that organizes a set into a number of disjoint sets, in which every element is a set and the union-find operation for two sets includes finding the union of two sets.

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [0] * n
        self.n = n

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr
        self.sz[yr] += self.sz[xr]

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def size(self, x):
        return self.sz[self.find(x)]

def check_isomorphic(graphs):
    n = graphs[0]
    uf = UnionFind(n)
    for graph in graphs:
        for edge in graph:
            x, y = edge
            if uf.find(x) != uf.find(y):
                uf.union(x, y)
            else:
                return "NO"
    return "YES"

def main():
    n, m1, m2 = map(int, input().split())
    graphs = [list(map(lambda x: (int(x) - 1, int(y) - 1) for y in input().split())) for _ in range(m1)]
    graphs += [list(map(lambda x: (int(x) - 1, int(y) - 1), input().split())) for _ in range(m2)]
    print(check_isomorphic(graphs))

if __name__ == "__main__":
    main()

This program first reads the number of vertices `n` and the number of edges for each graph. It then reads the edges for each graph and adds them to a list. After that, it calls the `check_isomorphic` function with the list of graphs as an argument. The `check_isomorphic` function creates a UnionFind instance, and for each edge in each graph, it finds the roots of the two vertices and unions them. If the two roots are different, it means there is a cycle, so the graphs are not isomorphic. If they are the same, it means the graphs are isomorphic.