# problem title : Reverse Nodes in K-Group
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        res = []
        for i in range(0, n, k):
            chunk = vals[i:i+k]
            if len(chunk) == k:
                res.extend(chunk[::-1])
            else:
                res.extend(chunk)
        print(*res)
if __name__ == '__main__':
    main()
