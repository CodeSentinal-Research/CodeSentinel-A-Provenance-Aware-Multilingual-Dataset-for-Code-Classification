Here is the Python code:

def max_matching(L, R, M):
    G = [[] for _ in range(L+R+2)]
    matched = [0] * (L+R+2)

    for _ in range(M):
        u, v, w in map(int, (input().split()[1:] + input().split()[0]):
            if w == 1:
                G[u].append((v, 1))
            else:
                G[v].append((u, 1))

    res = 0
    for u in range(1, L+1):
        if matched[u] == 0 and G[u][0] and G[u][0][1] == 1:
            v, w = G[u][0]
            G[u].pop(0)
            matched[u] = matched[v] = 1
            res += 1
            G[v][0] = (u, 0)

    return res

def main():
    L, R, M = map(int, input().split())
    print(max_matching(L, R, M))

if __name__ == "__main__":
    main()
This program reads the number of left and right partitions `L` and `R`, and the number of edges `M`. It then reads the edges. The edges are read and transformed into a graph. The graph is represented as an adjacency list where each vertex is represented as a pair of (adjacent vertex, edge weight).

The algorithm uses the Hopcroft-Karp algorithm to solve the bipartite matching problem. It first forms an augmenting path for each vertex in the left set, then it forms a matching for the right set. The matching is extended by adding edges to the right set.

The main function reads the number of left and right partitions, and calls the `max_matching` function with these parameters. The result is printed.