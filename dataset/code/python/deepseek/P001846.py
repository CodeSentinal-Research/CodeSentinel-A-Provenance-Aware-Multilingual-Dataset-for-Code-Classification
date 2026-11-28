Here is the Python code for the problem:

def solve(N, tree):
    nodes = [None] * (N + 1)
    for i in range(1, N + 1):
        idx = tree.index(i)
        nodes[i] = (idx, idx * 2 in tree, idx * 2 + 1 in tree)

    for i in range(1, N + 1):
        idx, left, right = nodes[i]
        if idx > 0 and nodes[idx][2] and nodes[idx][1] and nodes[idx][0] != idx - 1 and nodes[idx - 1][2] and nodes[idx - 1][1] and nodes[idx - 1][0] == idx:
            return 'YES'
        if idx < N and nodes[idx][2] and nodes[idx][1] and nodes[idx][0] != idx + 1 and nodes[idx + 1][2] and nodes[idx + 1][1] and nodes[idx + 1][0] == idx:
            return 'YES'

    return 'NO'


def main():
    N = int(input().strip())
    tree = list(map(int, input().strip().split()))
    print(solve(N, tree))


if __name__ == "__main__":
    main()

This program first reads the number of nodes and the tree from the input. It then calls the `solve` function with the given inputs and prints the result.