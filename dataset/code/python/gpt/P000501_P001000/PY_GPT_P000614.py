# problem title : Swap Kth Node from Beginning with Kth Node from End
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        i1 = k - 1
        i2 = n - k
        vals[i1], vals[i2] = vals[i2], vals[i1]
        print(*vals)
if __name__ == '__main__':
    main()
