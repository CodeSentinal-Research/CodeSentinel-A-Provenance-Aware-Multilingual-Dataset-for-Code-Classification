# problem title : Generate Binary Numbers
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        res = [bin(i)[2:] for i in range(1, n + 1)]
        print(*res)
if __name__ == '__main__':
    main()
