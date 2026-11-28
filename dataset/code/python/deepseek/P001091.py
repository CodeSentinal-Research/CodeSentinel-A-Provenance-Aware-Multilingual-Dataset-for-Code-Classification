Here is the Python code for the given problem. This code uses the Union-Find data structure to solve the problem efficiently.

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        self.p[a] = b

    def find(self, a):
        if self.p[a] != a:
            self.p[a] = self.find(self.p[a])
        return self.p[a]

def solve(n, edges, queries):
    uf = UnionFind(n)
    for a, b in edges:
        uf.union(a, b)

    for a, b in queries:
        rootA = uf.find(a)
        rootB = uf.find(b)
        print(rootA, rootB)

def main():
    n, q = map(int, input().split())
    edges = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(n - 1)]
    queries = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(q)]

    solve(n, edges, queries)

if __name__ == '__main__':
    main()

In this code, we first create a `UnionFind` class that represents a disjoint-set data structure. The `union` method merges two sets, and the `find` method finds the root of a set.

Then, in the `solve` function, we first initialize the `UnionFind`. We then for each edge, we call `uf.union(a, b)` to merge the sets containing `a` and `b`.

Finally, in the `main` function, we read the number of nodes and queries, and the edges and queries. We then call `solve` with the number of nodes and edges and queries.

Note: The input format for each query is (a b), where a and b are the indices of the vertices. The indices are 0-indexed, so 0 is considered the root of the tree.