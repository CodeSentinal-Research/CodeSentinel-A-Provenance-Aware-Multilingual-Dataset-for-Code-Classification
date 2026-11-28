# problem title : Pairwise Swap Nodes in Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        for i in range(0, n - 1, 2):
            vals[i], vals[i + 1] = vals[i + 1], vals[i]
        print(*vals)
if __name__ == '__main__':
    main()
