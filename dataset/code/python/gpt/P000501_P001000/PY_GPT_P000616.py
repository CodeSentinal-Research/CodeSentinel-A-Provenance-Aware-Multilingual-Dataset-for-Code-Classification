# problem title : Reverse Nodes in Even Positions
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        even_pos_vals = [vals[i] for i in range(1, n, 2)][::-1]
        res = list(vals)
        for i, val in zip(range(1, n, 2), even_pos_vals):
            res[i] = val
        print(*res)
if __name__ == '__main__':
    main()
