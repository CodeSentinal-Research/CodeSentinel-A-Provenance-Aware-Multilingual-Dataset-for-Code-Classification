# problem title : Matrix Cells in Distance Order
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        rows = int(tokens[0])
        cols = int(tokens[1])
        r0 = int(tokens[2])
        c0 = int(tokens[3])
        cells = [(r, c) for r in range(rows) for c in range(cols)]
        cells.sort(key=lambda p: abs(p[0] - r0) + abs(p[1] - c0))
        for r, c in cells:
            print(f"[{r},{c}]", end=" ")
        print()
if __name__ == '__main__':
    main()
