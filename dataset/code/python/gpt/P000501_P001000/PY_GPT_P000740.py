# problem title : Maze Paths with Diagonal Moves
# Solve the stated task using standard input and standard output.
import sys
def diagonal_paths(n, m, r, c, path):
    if r == n and c == m:
        print(path)
        return
    # Lexicographical order: D (diagonal), H (horizontal), V (vertical)
    if r < n and c < m:
        diagonal_paths(n, m, r + 1, c + 1, path + "D")
    if c < m:
        diagonal_paths(n, m, r, c + 1, path + "H")
    if r < n:
        diagonal_paths(n, m, r + 1, c, path + "V")
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n, m = int(tokens[0]), int(tokens[1])
        diagonal_paths(n, m, 1, 1, "")
if __name__ == '__main__':
    main()
