# problem title : Delete Alternate Nodes from Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = tokens[1:1+n]
        res = [vals[i] for i in range(0, n, 2)]
        print(*res)
if __name__ == '__main__':
    main()
