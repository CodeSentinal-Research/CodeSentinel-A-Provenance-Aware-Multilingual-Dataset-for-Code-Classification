import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    # Number of leaves in a complete binary tree with N nodes is ceil(N/2)
    print((n + 1) // 2)

if __name__ == "__main__":
    solve()

