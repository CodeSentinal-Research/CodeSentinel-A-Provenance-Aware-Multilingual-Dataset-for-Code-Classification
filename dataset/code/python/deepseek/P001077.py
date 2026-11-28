Here is the Python code for Kruskal's algorithm for finding the minimum spanning tree in a graph.

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n)

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootx = self.find(x)
        rooty = self.find(y)
        self.parent[rootx] = rooty

def kruskal_algorithm(n, edges):
    union_find = UnionFind(n)
    mst = []
    total_weight = 0

    edges.sort(key=lambda x: x[2])

    for edge in edges:
        u, v, w = edge
        if union_find.find(u) != union_find.find(v):
            union_find.union(u, v)
            mst.append(edge)
            total_weight += w
    return mst, total_weight

def main():
    n, m = map(int, input().split())
    edges = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        edges.append((u-1, v-1, w))  
    mst, total_weight = kruskal_algorithm(n, edges)
    print(total_weight)

if __name__ == "__main__":
    main()

In this code, the `UnionFind` class is used to implement the Union-Find data structure, which is used to find the union of two elements, or to check if two elements are in the same set. The `kruskal_algorithm` function implements the Kruskal's algorithm to find the minimum spanning tree and the `main` function handles the input and output.