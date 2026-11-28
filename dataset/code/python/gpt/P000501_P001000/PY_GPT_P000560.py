# problem title : Interleave the First Half of Queue
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        q = list(map(int, tokens[1:1+n]))
        half = n // 2
        first = q[:half]
        second = q[half:]
        res = []
        for a, b in zip(first, second):
            res.extend([a, b])
        print(*res)
if __name__ == '__main__':
    main()
