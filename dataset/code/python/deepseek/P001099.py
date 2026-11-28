Here is the Python code for the problem:

def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x], parent)
    return parent[x]

def union(x, y, parent, rank):
    x_rep = find(x, parent)
    y_rep = find(y, parent)
    if x_rep == y_rep:
        return False
    if rank[x_rep] < rank[y_rep]:
        parent[x_rep] = y_rep
        rank[y_rep] += rank[x_rep]
    else:
        parent[y_rep] = x_rep
        rank[x_rep] += rank[y_rep]
    return True

def solve():
    n, m = map(int, input().split())
    parent = list(range(n + 1))
    rank = [0] * (n + 1)
    for _ in range(m):
        x, y = map(int, input().split())
        if union(x, y, parent, rank):
            print("YES")
            return
    print("NO")

if __name__ == "__main__":
    solve()

This program uses the Union-Find algorithm to detect if a graph contains a cycle. The graph is represented as an undirected graph using adjacency list representation. The union-find data structure is used to keep track of the connected components of the graph. The `find` function is used to find the root of a node, and the `union` function is used to merge two nodes into one connected component.

The `solve` function reads the number of nodes and edges, and then reads the edges. It then calls the `union` function for each edge, and if a cycle is detected, it prints "YES" and exits. If no cycle is detected, it prints "NO".

The `parent` list and `rank` list are used to keep track of the parent of each node and the rank of each node, respectively. The `find` function is used to find the root of a node, and the `union` function is used to merge two nodes into one connected component.