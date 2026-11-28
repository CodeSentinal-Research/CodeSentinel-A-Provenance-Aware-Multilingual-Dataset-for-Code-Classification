import sys

def solve():
    n = int(sys.stdin.readline())
    # Internal nodes = N - Leaf nodes
    # Leaf nodes = ceil(N/2)
    leaves = (n + 1) // 2
    print(n - leaves)

if __name__ == "__main__":
    solve()

