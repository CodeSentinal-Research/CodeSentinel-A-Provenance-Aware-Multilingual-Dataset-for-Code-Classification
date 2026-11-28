Here is the Python code:

def find_redundant_connection(edges):
    parent = list(range(len(edges)))

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    for u, v in edges:
        pu, pv = find(u-1), find(v-1)
        if pu == pv:
            return u, v
        parent[pu] = pv

    return None


def main():
    n = int(input().strip())
    edges = []

    for _ in range(n):
        u, v = map(int, input().strip().split())
        edges.append((u, v))

    u, v = find_redundant_connection(edges)
    print(u, v)


if __name__ == "__main__":
    main()

In this code, the `find_redundant_connection` function uses the Union-Find algorithm to find the root of each component in the graph. If two vertices in the same component have the same root, it means that there is a cycle in the graph. So, the edge connecting these two vertices is redundant.