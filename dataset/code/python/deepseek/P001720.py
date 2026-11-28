def solve():
    n = int(input().strip())
    values = list(map(int, input().strip().split()))
    parent = [[0, 0] for _ in range(n)]
    depth = [0] * n

    def build_tree():
        for i in range(n):
            parent[i] = [values[2 * i], values[2 * i + 1]]
            depth[values[2 * i]] = max(depth[values[2 * i]], depth[i])

    build_tree()
    max_depth = max(depth)
    print(sum(values[i] for i in range(n) if depth[i] == max_depth))


def main():
    solve()


if __name__ == "__main__":
    main()
This code first reads the number of nodes `n` and the node values. It then creates a binary tree based on these values. The `depth` array stores the depth of each node, and the `parent` array stores the parent node of each node. The `build_tree` function populates these arrays. Finally, it calculates the maximum depth and prints the sum of all nodes at the maximum depth.