# problem title : Generate All Paths with Variable Length Jumps
# Solve the stated task using standard input and standard output.
import sys
def var_jump_paths(n, m, r, c, path):
    if r == n and c == m:
        print(path)
        return
    # Horizontal moves H1, H2, ...
    for k in range(1, m - c + 1):
        var_jump_paths(n, m, r, c + k, path + f"H{k}")
    # Vertical moves V1, V2, ...
    for k in range(1, n - r + 1):
        var_jump_paths(n, m, r + k, c, path + f"V{k}")
    # Diagonal moves D1, D2, ...
    for k in range(1, min(n - r, m - c) + 1):
        var_jump_paths(n, m, r + k, c + k, path + f"D{k}")
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n, m = int(tokens[0]), int(tokens[1])
        var_jump_paths(n, m, 1, 1, "")
if __name__ == '__main__':
    main()
