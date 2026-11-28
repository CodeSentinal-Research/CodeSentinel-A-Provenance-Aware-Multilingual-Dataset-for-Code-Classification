# problem title : Swap Two Nodes Without Swapping Data
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        x = int(tokens[1+n])
        y = int(tokens[2+n])
        if x in vals and y in vals:
            ix, iy = vals.index(x), vals.index(y)
            vals[ix], vals[iy] = vals[iy], vals[ix]
        print(*vals)
if __name__ == '__main__':
    main()
